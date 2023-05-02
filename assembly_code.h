#define MAXLINE 128
#define MAXLENGTH 128

typedef struct 
{
    unsigned int address[MAXLINE];
    unsigned opcode[MAXLINE][10];
}ASMC;
