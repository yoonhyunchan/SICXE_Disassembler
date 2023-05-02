#include <stdio.h>
#include <string.h>
#include "inst_reg.h"
#include "objcode.h"
#include "objcode_hex.h"
#include "assembly_code.h"

#define REGISTER_SIZE 8
#define INST_SIZE 59

void print_objcode(OBJ_HEX object_code_hex)
{
    printf("H %s ", object_code_hex.program_name);
    printf("%s ", object_code_hex.program_starting_addr);
    printf("%s\n", object_code_hex.program_length);
    for (int i = 0; i < object_code_hex.program_line; i++)
    {
        printf("%c ", object_code_hex.OBJ_LINE[i].type);
        int size = object_code_hex.OBJ_LINE[i].size;
        for (int k = 0; k < 4; k++)
        {
            if (k == 3)
                printf(" ");
            printf("%02X", object_code_hex.OBJ_LINE[i].start_addr_line_length[k]);
        }
        printf(" ");

        for (int k = 0; k < size / 2; k++)
        {
            printf("%02X", object_code_hex.OBJ_LINE[i].code_hex[k]);
        }
        printf("\n");
    }
    printf("========================================\n");
}

int main(void)
{
    OBJ objcode_string;
    OBJ_HEX object_code_hex;
    ASMC assembly_code;
    objcode_string = get_obj();

    if (objcode_string.obj_buf[0][0] == 'H')
    {
        strncpy(object_code_hex.program_name, *(objcode_string.obj_buf) + 1, 6);
        strncpy(object_code_hex.program_starting_addr, *(objcode_string.obj_buf) + 7, 6);
        strncpy(object_code_hex.program_length, *(objcode_string.obj_buf) + 13, 6);
    }
    for (int j = 1; j < objcode_string.obj_line_length; j++)
    {
        char code_line_str[128];
        int size;
        char type = objcode_string.obj_buf[j][0];
        object_code_hex.OBJ_LINE[j - 1].type = type;
        if (objcode_string.obj_buf[j][0] == 'E')
        {
            object_code_hex.program_line = j - 1;
            strncpy(object_code_hex.E_starting_addr, *(objcode_string.obj_buf) + j * MAXLENGTH + 1, 6);
        }
        else
        {
            strncpy(code_line_str, objcode_string.obj_buf[j] + 1, 8);
            ascii_to_hex(code_line_str, strlen(code_line_str), object_code_hex.OBJ_LINE[j - 1].start_addr_line_length);

            if (type == 'T')
            {
                strncpy(code_line_str, objcode_string.obj_buf[j] + 9, sizeof(objcode_string.obj_buf[j]));
                size = strlen(code_line_str);
                object_code_hex.OBJ_LINE[j - 1].size = size;
                ascii_to_hex(code_line_str, strlen(code_line_str), object_code_hex.OBJ_LINE[j - 1].code_hex);
            }
        }
    }
    print_objcode(object_code_hex);

    for (int i = 0; i < object_code_hex.program_line; i++)
    {
        if (object_code_hex.OBJ_LINE[i].type == 'T')
        {
            unsigned int a, b, c;
            a = object_code_hex.OBJ_LINE[i].start_addr_line_length[0] << 16;
            b = object_code_hex.OBJ_LINE[i].start_addr_line_length[1] << 8;
            c = object_code_hex.OBJ_LINE[i].start_addr_line_length[2];
            for (int j = 0; j < object_code_hex.OBJ_LINE[i].start_addr_line_length[3]; j++)
            {

                for (int k = 0; k < INST_SIZE; k++)
                {
                    if (object_code_hex.OBJ_LINE[i].code_hex[j] >> 2 == instruction[k].opcode >> 2)
                    {

                        if (instruction[k].format == 1)
                        {
                            printf("%04X %s\n", j + a + b + c, instruction[k].Mnemonic);
                            break;
                        }
                        else if (instruction[k].format == 2)
                        {

                            printf("%04X %s\n", j + a + b + c, instruction[k].Mnemonic);
                            j += 1;
                            break;
                        }
                        else if (instruction[k].format == 3)
                        {

                            printf("%04X ", j + a + b + c);
                            if (object_code_hex.OBJ_LINE[i].code_hex[j + 1] >> 4 % 0x10 == 1)
                            {
                                j += 1;
                                printf("+");
                            }
                            printf("%s\n", instruction[k].Mnemonic);
                            j += 2;
                            break;
                        }
                    }
                }
            }
            printf("\n");
        }
    }

    return 0;
}
