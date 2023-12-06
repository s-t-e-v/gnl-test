#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

static int test6()
{
    int		fd;
    char    *line;

    printf("\n> test 6\n");

    fd = open("test6.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), -1);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    close(fd);
    return (1);
}

static int test5()
{
    int		fd;
    char    *line;

    printf("\n> test 5\n");

    fd = open("test5.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), -1);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    close(fd);
    return (1);
}

static int test4()
{
    int		fd;
    char    *line;

    printf("\n> test 4\n");

    fd = open("test4.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), -1);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    close(fd);
    return (1);
}

static int test3()
{
    int		fd;
    char    *line;

    printf("\n> test 3\n");

    fd = open("test3.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), -1);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    close(fd);
    return (1);
}

static int test2()
{
    int		fd;
    char    *line;

    printf("\n> test 2\n");

    fd = open("test2.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), -1);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    close(fd);
    return (1);
}

static int test1()
{
    int		fd;
    char    *line;

    printf("\n> test 1\n");

    fd = open("test1.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), -1);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    line =  get_next_line(fd);
    printf("%s", line);
    if (line)
        free(line);
    close(fd);
    return (1);
}

int main(void)
{
    printf("--- Tests");
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return (0);
}
