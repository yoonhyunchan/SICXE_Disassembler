typedef struct
{
    char Mnemonic[6];
    int format;
    unsigned short int opcode;
} instruction_set;
instruction_set instruction[] = {
    {"ADD", 3, 0x18},
    {"ADDF", 3, 0x58},
    {"ADDR", 2, 0x90},
    {"AND", 3, 0x40},
    {"CLEAR", 2, 0xB4},
    {"COMP", 3, 0x28},
    {"COMPF", 3, 0x88},
    {"COMPR", 2, 0xA0},
    {"DIV", 3, 0x24},
    {"DIVF", 3, 0x64},
    {"DIVR", 2, 0x9C},
    {"FIX", 1, 0xC4},
    {"FLOAT", 1, 0xC0},
    {"HIO", 1, 0xF4},
    {"J", 3, 0x3C},
    {"JEQ", 3, 0x30},
    {"JGT", 3, 0x34},
    {"JLT", 3, 0x38},
    {"JSUB", 3, 0x48},
    {"LDA", 3, 0x00},
    {"LDB", 3, 0x68},
    {"LDCH", 3, 0x50},
    {"LDF", 3, 0x70},
    {"LDL", 3, 0x08},
    {"LDS", 3, 0x6C},
    {"LDT", 3, 0x74},
    {"LDX", 3, 0x04},
    {"LPS", 3, 0xD0},
    {"MUL", 3, 0x20},
    {"MULF", 3, 0x60},
    {"MULR", 3, 0x98},
    {"NORM", 1, 0xC8},
    {"OR", 3, 0x44},
    {"RD", 3, 0xD8},
    {"RMO", 2, 0xAC},
    {"RSUB", 3, 0x4C},
    {"SHIFTL", 2, 0xA4},
    {"SHIFTR", 2, 0xA8},
    {"SIO", 1, 0xF0},
    {"SSK", 3, 0xEC},
    {"STA", 3, 0x0C},
    {"STB", 3, 0x78},
    {"STCH", 3, 0x54},
    {"STF", 3, 0x90},
    {"STI", 3, 0xD4},
    {"STL", 3, 0x14},
    {"STS", 3, 0x7C},
    {"STSW", 3, 0xE8},
    {"STT", 3, 0x84},
    {"STX", 3, 0x10},
    {"SUB", 3, 0x1C},
    {"SUBF", 3, 0x5C},
    {"SUBR", 2, 0x94},
    {"SVC", 2, 0xB0},
    {"TD", 3, 0xE0},
    {"TIO", 1, 0xF8},
    {"TIX", 3, 0x2C},
    {"TIXR", 2, 0xB8},
    {"WD", 3, 0xDC},
};
typedef struct
{
    char Mnemonic_R[2];
    int number;

} Register;

Register R[] = {
    {"A", 0},
    {"X", 1},
    {"L", 2},
    {"B", 3},
    {"S", 4},
    {"T", 5},
    {"F", 6},
    {"PC", 8},
    {"SW", 9}};

