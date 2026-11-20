#include "get_next_line.h"

void    get_bu(char **buff)
{
    *buff = malloc(2);
    (*buff)[0] = '1';
    (*buff)[1] = '\0';
}

int main()
{
   char *buffer;
   get_bu(&buffer);
   printf("%s", buffer);
   free(buffer);
}