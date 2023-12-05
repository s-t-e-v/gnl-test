#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int		fd;
    char    *line;

    fd = open("test1.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), 1);
    line =  get_next_line(fd);
    printf("%s\n", line);
    close(fd);
    if (line)
        free(line);
    return (0);
}
