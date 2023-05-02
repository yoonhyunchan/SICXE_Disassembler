#define MAXLINE 128
#define MAXLENGTH 128

typedef struct
{
    int obj_line_length;
    char obj_buf[MAXLENGTH][MAXLINE];
} OBJ;

OBJ get_obj()
{
    OBJ obj;
    FILE *objcode = NULL;
    int i = 0;
    int obj_line_length = 0;

    objcode = fopen("./test.obj", "r");
    while (feof(objcode) == 0)
    {
        fgets(obj.obj_buf[i], MAXLENGTH, objcode);
        i++;
        obj.obj_line_length = i;
    }

    return obj;
}
