#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <bsd/string.h>

static int  testpassed = 0;
static int  nb_test = 0;

static int test6()
{
    int		fd;
    char    *line;
    int     ntest = 0;
    int     passed = 0;

    nb_test++;
    printf("\n> test 6");

    fd = open("test6.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), -1);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "Hello World");
    // printf("%s", line);
    if (line)
        free(line);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "(null)");
    // printf("%s", line);
    if (line)
        free(line);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "(null)");
    // printf("%s", line);
    if (line)
        free(line);
    close(fd);

    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf(" - KO");
    return (1);
}

static int test5()
{
    int		fd;
    char    *line;
    int     ntest = 0;
    int     passed = 0;

    nb_test++;
    printf("\n> test 5");

    fd = open("test5.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), -1);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "Bonjour");
    // printf("%s", line);
    if (line)
        free(line);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "(null)");
    // printf("%s", line);
    if (line)
        free(line);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "(null)");
    // printf("%s", line);
    if (line)
        free(line);
    close(fd);

    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf(" - KO");
    return (1);
}

static int test4()
{
    int		fd;
    char    *line;
    int     ntest = 0;
    int     passed = 0;

    nb_test++;
    printf("\n> test 4");

    fd = open("test4.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), -1);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "a\n");
    // printf("%s", line);
    if (line)
        free(line);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "(null)");
    // printf("%s", line);
    if (line)
        free(line);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "(null)");
    // printf("%s", line);
    if (line)
        free(line);
    close(fd);

    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf(" - KO");
    return (1);
}

static int test3()
{
    int		fd;
    char    *line;
    int     ntest = 0;
    int     passed = 0;

    nb_test++;
    printf("\n> test 3");

    fd = open("test3.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), -1);


    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "\n");
    // printf("%s", line);
    if (line)
        free(line);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "(null)");
    // printf("%s", line);
    if (line)
        free(line);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "(null)");
    // printf("%s", line);
    if (line)
        free(line);
    close(fd);

    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf(" - KO");
    return (1);
}

static int test1()
{
    int		fd;
    char    *line;
    int     ntest = 0;
    int     passed = 0;

    nb_test++;
    printf("\n> test 1");

    fd = open("test1.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), -1);


    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "abcdefghijklmnopqrstuvwxyz\n");
    // printf("%s", line);
    if (line)
        free(line);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    // printf("%s", line);
    if (line)
        free(line);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "0123456789");
    // printf("%s", line);
    if (line)
        free(line);
    close(fd);

    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf(" - KO");
    return (1);
}

static int test2()
{
    int		fd;
    char    *line;
    int     ntest = 0;
    int     passed = 0;

    nb_test++;
    printf("\n> test 2");

    fd = open("test2.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), -1);


    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "(null)");
    // printf("%s", line);
    if (line)
        free(line);

    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "(null)\n");
    // printf("%s", line);
    if (line)
        free(line);
    
    ntest++;
    line =  get_next_line(fd);
    passed += !strcmp(line, "(null)\n");
    // printf("%s", line);
    if (line)
        free(line);
    close(fd);

    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf(" - KO");
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

    if (nb_test == testpassed)
        printf("\nAll tests passed :-) (passed: %d/%d)\n", testpassed, nb_test);
    else
        printf("\nSome tests failed :/ (passed: %d/%d)\n", testpassed, nb_test);

    return (0);
}
