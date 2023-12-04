#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int		fd;

    fd = open("test1.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), 1);
    printf("%s\n", get_next_line(fd));
    close(fd);
    return (0);
}
