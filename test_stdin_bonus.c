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

static int test()
{
    char    *line;
    int     ntest;
    int     passed = 0;
    char    *lines[] = {
        "This is line 1\n",
        "This is line 2\n",
        "This is line 3"
    };

    nb_test++;
    printf("\n+ test stdin bonus");

    ntest = 0;
    while (ntest < (int)(sizeof(lines)/sizeof(lines[0])))
    {
        line =  get_next_line(0);
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
    test();

    if (nb_test == testpassed)
        printf("\nAll tests passed :-) (%d/%d)\n", testpassed, nb_test);
    else
        printf("\nSome tests failed :/ (passed: %d/%d)\n", testpassed, nb_test);

    return (0);
}
