#include "get_next_line.h"

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *buff = ;
    printf("%d", read(fd, buff, 3));
}