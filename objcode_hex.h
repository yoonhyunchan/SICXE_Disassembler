#define MAXLINE 128
#define MAXLENGTH 128




typedef struct 
{
    char type;
    int size;
    unsigned start_addr_line_length[10];
    unsigned code_hex[MAXLENGTH];
}obj_code_line;



typedef struct
{
    char program_name[10];
    char program_starting_addr[10];
    char program_length[10];
    char E_starting_addr[10];
    int program_line;
    obj_code_line OBJ_LINE[MAXLINE];

}OBJ_HEX;

unsigned int ascii_to_hex(const char* str, int size, unsigned* hex)
{
    unsigned int i, h, high, low;
    for (h = 0, i = 0; i < size; i += 2, ++h) {
        high = (str[i] > '9') ? str[i] - 'A' + 10 : str[i] - '0';
        low = (str[i + 1] > '9') ? str[i + 1] - 'A' + 10 : str[i + 1] - '0';
        hex[h] = (high << 4) | low;
    }
    return h;
}




