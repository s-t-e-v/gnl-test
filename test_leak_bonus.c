#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <bsd/string.h>
#include "../get_next_line_bonus.h"

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

    if (nb_test == testpassed)
        printf("\nAll tests passed :-) (%d/%d)\n", testpassed, nb_test);
    else
        printf("\nSome tests failed :/ (passed: %d/%d)\n", testpassed, nb_test);

    return (0);
}
