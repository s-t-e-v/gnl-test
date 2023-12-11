#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <bsd/string.h>
#include "get_next_line_bonus.h"

static int  testpassed = 0;
static int  nb_test = 0;


static void print_string_with_escapes(const char *str) {
	if (str){
		while (*str) {
			if (isprint((unsigned char)*str)) {
				putchar(*str);
			} else {
				printf("\\x%02x", (unsigned char)*str);
			}
			str++;
		}
	}
    else
        printf("(null)");
}


static int test9()
{
    int     i;
    char    *line;
    int     ntest;
    int     passed = 0;
    char    *lines[] = {
        "Je\n",
        "pense que \n",
        "De grands pouvoirs impliquent de grandes responsabilites!\n",
        "Fortune, ",
        "Gloire et Pouvoir!",
};
    char    *paths[] = {
        "test9_1.txt",
        "test9_2.txt",
        "test9_3.txt",
        "test9_4.txt",
        "test9_5.txt",
    };
    int		fd[sizeof(lines)/sizeof(lines[0])];

    nb_test++;
    printf("\n+ test 9");

    ntest = 0;
    while (ntest < (int)(sizeof(fd)/sizeof(fd[0])))
    {
        fd[ntest] = open(paths[ntest], 00);
        if (fd[ntest] < 0)
            return (printf("Error opening file!\n"), -1);
        line =  get_next_line(fd[ntest]);
        if ((!line && !lines[ntest]) || (line && !strcmp(line, lines[ntest])))
            passed++;
        else
        {
            printf("\n|    gnl call #%d [fd = %d]", ntest + 1, fd[ntest]);
            printf("\n|      expected:");
            print_string_with_escapes(lines[ntest]);
            printf("\n|      actual  :");
            print_string_with_escapes(line);
        }
        if (line)
            free(line);
        ntest++;
    }
    i = 0;
    while (i < (int)(sizeof(fd)/sizeof(fd[0])))
        close(fd[i++]);
    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf("\n+--------> KO");
    return (1);
}

static int test8()
{
    int		fd;
    char    *line;
    int     ntest;
    int     passed = 0;
    char    *lines[] = {
        "\n",
        "    Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n",
        "    Pellentesque efficitur augue a lorem malesuada accumsan.\n",
        "    Praesent bibendum nisi vitae neque iaculis, ut tincidunt magna finibus.\n",
        "    Fusce et sem maximus, imperdiet nisl ac, consectetur est.\n",
        "    Nunc nec felis molestie, tincidunt tellus vel, condimentum massa.\n",
        "    Praesent luctus lorem et nisi rutrum tempor.\n",
        "\n",
        "    Aenean dictum nibh eget sapien ornare, in bibendum nulla lobortis.\n",
        "    Praesent id enim ac mauris luctus tincidunt sed aliquam libero.\n",
        "\n",
        "    Morbi euismod augue sit amet libero luctus, vitae hendrerit lorem finibus.\n",
        "    Aenean vitae odio aliquam, maximus ligula id, interdum ligula.\n",
        "    Cras sit amet ligula tempus, sodales eros vitae, aliquet risus.\n",
        "\n",
        "    Pellentesque ac metus at dolor porta malesuada.\n",
        "    Nulla bibendum orci id lectus accumsan feugiat.\n",
        "    Pellentesque nec elit aliquam, gravida tellus vitae, fermentum dolor.\n",
        "    Curabitur dictum mauris quis interdum ultricies.\n",
        "    Donec sit amet ante nec metus pulvinar sollicitudin in vel felis.\n",
        "    Morbi vel augue nec lacus vestibulum accumsan.\n",
        "\n",
        "    In pulvinar tortor non viverra finibus.\n",
        "    Duis sollicitudin mauris id sapien malesuada pellentesque.\n",
        "    Quisque vel leo nec ex feugiat luctus eu vitae arcu.\n",
        "    Integer ultrices orci sed neque malesuada tristique.\n",
        NULL,
    };

    nb_test++;
    printf("\n+ test 8");

    fd = open("test8.txt", 00);
    if (fd < 0)
        return (printf("Error opening file!\n"), -1);

    ntest = 0;
    while (ntest < (int)(sizeof(lines)/sizeof(lines[0])))
    {
        line =  get_next_line(fd);
        if ((!line && !lines[ntest]) || (line && !strcmp(line, lines[ntest])))
            passed++;
        else
        {
            printf("\n|    gnl call #%d", ntest + 1);
            printf("\n|      expected:");
            print_string_with_escapes(lines[ntest]);
            printf("\n|      actual  :");
            print_string_with_escapes(line);
        }
        if (line)
            free(line);
        ntest++;
    }

    close(fd);
    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf("\n+--------> KO");
    return (1);
}

static int test7()
{
 int		fd;
    char    *line;
    int     ntest;
    int     passed = 0;
    char    *lines[] = {
        "\n",
        "\n",
        "\n",
        "\n",
        "\n",
        "\n",
        NULL,
        NULL,
    };

    nb_test++;
    printf("\n+ test 7");

    fd = open("test7.txt", 00);
    if (fd < 0)
        return (printf("Error opening file!\n"), -1);

    ntest = 0;
    while (ntest < (int)(sizeof(lines)/sizeof(lines[0])))
    {
        line =  get_next_line(fd);
        if ((!line && !lines[ntest]) || (line && !strcmp(line, lines[ntest])))
            passed++;
        else
        {
            printf("\n|    gnl call #%d", ntest + 1);
            printf("\n|      expected:");
            print_string_with_escapes(lines[ntest]);
            printf("\n|      actual  :");
            print_string_with_escapes(line);
        }
        if (line)
            free(line);
        ntest++;
    }
    close(fd);
    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf("\n+--------> KO");
    return (1);
}

static int test6()
{
 int		fd;
    char    *line;
    int     ntest;
    int     passed = 0;
    char    *lines[] = {
        "Hello World\n",
        NULL,
        NULL,
    };

    nb_test++;
    printf("\n+ test 6");

    fd = open("test6.txt", 00);
    if (fd < 0)
        return (printf("Error opening file!\n"), -1);

    ntest = 0;
    while (ntest < (int)(sizeof(lines)/sizeof(lines[0])))
    {
        line =  get_next_line(fd);
        if ((!line && !lines[ntest]) || (line && !strcmp(line, lines[ntest])))
            passed++;
        else
        {
            printf("\n|    gnl call #%d", ntest + 1);
            printf("\n|      expected:");
            print_string_with_escapes(lines[ntest]);
            printf("\n|      actual  :");
            print_string_with_escapes(line);
        }
        if (line)
            free(line);
        ntest++;
    }

    close(fd);
    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf("\n+--------> KO");
    return (1);
}

static int test5()
{
    int		fd;
    char    *line;
    int     ntest;
    int     passed = 0;
    char    *lines[] = {
        "Bonjour",
        NULL,
        NULL,
    };

    nb_test++;
    printf("\n+ test 5");

    fd = open("test5.txt", 00);
    if (fd < 0)
        return (printf("Error opening file!\n"), -1);

    ntest = 0;
    while (ntest < (int)(sizeof(lines)/sizeof(lines[0])))
    {
        line =  get_next_line(fd);
        if ((!line && !lines[ntest]) || (line && !strcmp(line, lines[ntest])))
            passed++;
        else
        {
            printf("\n|    gnl call #%d", ntest + 1);
            printf("\n|      expected:");
            print_string_with_escapes(lines[ntest]);
            printf("\n|      actual  :");
            print_string_with_escapes(line);
        }
        if (line)
            free(line);
        ntest++;
    }

    close(fd);
    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf("\n+--------> KO");
    return (1);
}

static int test4()
{
    int		fd;
    char    *line;
    int     ntest;
    int     passed = 0;
    char    *lines[] = {
        "a\n",
        NULL,
        NULL,
    };

    nb_test++;
    printf("\n+ test 4");

    fd = open("test4.txt", 00);
    if (fd < 0)
        return (printf("Error opening file!\n"), -1);

    ntest = 0;
    while (ntest < (int)(sizeof(lines)/sizeof(lines[0])))
    {
        line =  get_next_line(fd);
        if ((!line && !lines[ntest]) || (line && !strcmp(line, lines[ntest])))
            passed++;
        else
        {
            printf("\n|    gnl call #%d", ntest + 1);
            printf("\n|      expected:");
            print_string_with_escapes(lines[ntest]);
            printf("\n|      actual  :");
            print_string_with_escapes(line);
        }
        if (line)
            free(line);
        ntest++;
    }

    close(fd);
    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf("\n+--------> KO");
    return (1);
}

static int test3()
{
    int		fd;
    char    *line;
    int     ntest;
    int     passed = 0;
    char    *lines[] = {
        "\n",
        NULL,
        NULL,
    };

    nb_test++;
    printf("\n+ test 3");

    fd = open("test3.txt", 00);
    if (fd < 0)
        return (printf("Error opening file!\n"), -1);

    ntest = 0;
    while (ntest < (int)(sizeof(lines)/sizeof(lines[0])))
    {
        line =  get_next_line(fd);
        if ((!line && !lines[ntest]) || (line && !strcmp(line, lines[ntest])))
            passed++;
        else
        {
            printf("\n|    gnl call #%d", ntest + 1);
            printf("\n|      expected:");
            print_string_with_escapes(lines[ntest]);
            printf("\n|      actual  :");
            print_string_with_escapes(line);
        }
        if (line)
            free(line);
        ntest++;
    }

    close(fd);
    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf("\n+--------> KO");
    return (1);
}

static int test2()
{
    int		fd;
    char    *line;
    int     ntest = 0;
    int     passed = 0;

    nb_test++;
    printf("\n+ test 2");

    fd = open("test2.txt", 00);

    if (fd < 0)
        return (printf("Error opening file!\n"), -1);


    ntest++;
    line =  get_next_line(fd);
    if (line == NULL)
        passed++;
    else
    {
        printf("\n|    gnl call #1");
        printf("\n|      expected:%s", "(null)");
        printf("\n|      actual  :%s", line);
    }
    if (line)
        free(line);

    ntest++;
    line =  get_next_line(fd);
    if (line == NULL)
        passed++;
    else
    {
        printf("\n|    gnl call #2");
        printf("\n|      expected:%s", "(null)");
        printf("\n|      actual  :%s", line);
    }
    if (line)
        free(line);
    
    ntest++;
    line =  get_next_line(fd);
    if (line == NULL)
        passed++;
    else
    {
        printf("\n|    gnl call #3");
        printf("\n|      expected:%s", "(null)");
        printf("\n|      actual  :%s", line);
    }
    if (line)
        free(line);
    close(fd);

    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf("\n+--------> KO");
    return (1);
}

static int test1()
{
    int		fd;
    char    *line;
    int     ntest;
    int     passed = 0;
    char    *lines[] = {
        "abcdefghijklmnopqrstuvwxyz\n",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n",
        "0123456789",
    };

    nb_test++;
    printf("\n+ test 1");

    fd = open("test1.txt", 00);
    if (fd < 0)
        return (printf("Error opening file!\n"), -1);

    ntest = 0;
    while (ntest < (int)(sizeof(lines)/sizeof(lines[0])))
    {
        line =  get_next_line(fd);
        if ((!line && !lines[ntest]) || (line && !strcmp(line, lines[ntest])))
            passed++;
        else
        {
            printf("\n|    gnl call #%d", ntest + 1);
            printf("\n|      expected:");
            print_string_with_escapes(lines[ntest]);
            printf("\n|      actual  :");
            print_string_with_escapes(line);
        }
        if (line)
            free(line);
        ntest++;
    }

    close(fd);
    if (ntest == passed)
    {
        printf(" - OK");
        testpassed++;
    }
    else
        printf("\n+--------> KO");
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
    test7();
    test8();
    test9();

    if (nb_test == testpassed)
        printf("\nAll tests passed :-) (%d/%d)\n", testpassed, nb_test);
    else
        printf("\nSome tests failed :/ (passed: %d/%d)\n", testpassed, nb_test);

    return (0);
}
