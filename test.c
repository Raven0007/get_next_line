#include "get_next_line.h"

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char str[3];
    printf("%zd", read(fd, str, 3));
    printf("%s\n", str);
    printf("%zd", read(fd, str, 3));
    printf("%s\n", str);
    printf("%zd", read(fd, str, 3));
    printf("%s\n", str);
    printf("%zd", read(fd, str, 3));
    printf("%s\n", str);
    printf("%zd", read(fd, str, 3));
    printf("%s\n", str);
    printf("%zd", read(fd, str, 3));
    printf("%s\n", str);

    // printf("%s\n", str);
}