#include "file_utils.h"
#include "../get_next_line.h"

void populate_expected(char *buffer, int n)
{
	int i = 0;
	while(i < n)
	{
		i += sprintf(buffer + i, "0123456789");
	}
	buffer[n] = 0;
}

char *decode(char *buffer, char *result) {
	int offset = 0;

	while (*buffer)
	{
		if (*buffer >= '0' && *buffer <= '9') {
			int size = atoi(buffer);
			for (int i = 0; i < size; i++) {
				result[offset] = (offset % 26) + 'a';
				offset++;
			}
			while(*buffer >= '0' && *buffer <= '9') {
				buffer++;
			}
		} else if (*buffer == '\n') {
			result[offset++] = '\n';
			buffer++;
		} else {
			fprintf(stderr, "Fix your shit");
		}
	}
	result[offset] = 0;
	return result;
}

int count_lines(char *str) {
	int i = 0;
	char *s = str;
	while(s != NULL) {
		s = strchr(s, '\n');
		if (s != NULL)
			s++;
		i++;
	}
	if (str[strlen(str) - 1] == '\n')
		i--;
	return i;
}

char *get_line(char *s, int i) {
	while(*s && i > 0) {
		if (*s == '\n')
			i--;
		s++;
	}
	if (i > 0 || *s == 0) return NULL;
	char *next = strchr(s, '\n');
	if (next) {
		char *res = calloc(next - s + 2, 1);
		strncpy(res, s, next - s + 2);
		res[next - s + 1] = 0;
		return res;
	} else {
		return strdup(s);
	}
}

int test_limit(char *encoding) {
	int res = 1;
	
	char content[10000];
	decode(encoding, content);
	FILE * file = fopen("limits.txt", "w");
	fprintf(file, "%s", content);
	fclose(file);
	reset_malloc_mock();
	int fd = open("limits.txt", O_RDONLY);
	int lines = count_lines(content) + 1;
	for (int i = 0; i < lines; i++) {
		char *expected = get_line(content, i);
		res = test_gnl_func_limits(fd, expected, i, content, "limits.txt");
		if (expected != NULL)
			free(expected);
	}
	close(fd);
	int no_leaks = leak_check();
	no_leaks = null_check_gnl("limits.txt") && no_leaks;
	if (!no_leaks) {
		fprintf(errors_file, "for file:\n");
		print_file_content(content);
		fprintf(errors_file, "\n\n");
	}
	return res && no_leaks;
}

int main(int argn, char **argv)
{
	setup_framework(argn, argv);
	printf(BMAG "BUFFER_SIZE" NC ": %i\n", BUFFER_SIZE);


	int fd = open("1char.txt", O_RDONLY);
	/* 1 */ test_gnl_func(fd, "0", "1char.txt");
	/* 2 */ test_gnl_func(fd, NULL, "1char.txt");

    char *name = "read_error.txt";
    int fd = open(name, O_RDONLY);
    /* 1 */ test_gnl_func(fd, "aaaaaaaaaa\n", "read_error.txt"); //test_gnl(fd, "aaaaaaaaaa\n");
    /* 2 */  test_gnl_func(fd, "bbbbbbbbbb\n", "read_error.txt"); // test_gnl(fd, "bbbbbbbbbb\n");
    // set the next read call to return -1
    next_read_error = 1;
    if (BUFFER_SIZE > 100) {
        char *temp;
        do {
            temp = get_next_line(fd);
            free(temp);
        } while (temp != NULL);
    }
    /* 3 */ test_gnl_func(fd, NULL, "read_error.txt"); // test_gnl(fd, NULL);
    next_read_error = 0;
    close(fd);
    fd = open(name, O_RDONLY);
    printf("fd = %d\n", fd);
    /* 4 */ test_gnl_func(fd, "aaaaaaaaaa\n", "read_error.txt"); // test_gnl(fd, "aaaaaaaaaa\n");
    /* 5 */ test_gnl_func(fd, "bbbbbbbbbb\n", "read_error.txt"); // test_gnl(fd, "bbbbbbbbbb\n");
    /* 6 */ test_gnl_func(fd, "cccccccccc\n", "read_error.txt"); // test_gnl(fd, "cccccccccc\n");
    /* 7 */ test_gnl_func(fd, "dddddddddd\n", "read_error.txt"); // test_gnl(fd, "dddddddddd\n");
    /* 8 */ test_gnl_func(fd, NULL, "read_error.txt"); // test_gnl(fd, NULL);

	// char *tests[18] = {"9", "9\n", "10", "10\n", "11", "11\n", "19", "19\n", "20", "20\n", "21", "21\n",
	// 	"9\n9\n", "9\n10", "9\n10\n",
	// 	"10\n8\n", "10\n9", "10\n9\n"
	// };

	// if (BUFFER_SIZE == 10) {
	// 	/*
	// 	 * This tests what happens when newlines are close to the BUFFER_SIZE.
	// 	 * 
	// 	 * For each of the strings defined in char *tests[18] above, it will create a file with what that string encodes. 
	// 	 * 
	// 	 * For example, if the string is: "10\n8\n" it will create a file with 10 chars, a newline, 8 chars and newline.
	// 	 * Then it will use that file as a test for the get_next_line function
	// 	 */
	// 	BASE_TEST("limits", {
	// 		for (int i = 0; i < 18; i++) {
	// 			res = test_limit(tests[i]) && res;
	// 		}
	// 	});
	// }

	// // The file being read is 'lines_around_10.txt'
	// TEST("stdin", {
	// 	int fd = STDIN_FILENO;
	// 	/* 1 */ test_gnl(fd, "0123456789\n");
	// 	/* 2 */ test_gnl(fd, "012345678\n");
	// 	/* 3 */ test_gnl(fd, "90123456789\n");
	// 	/* 4 */ test_gnl(fd, "0123456789\n");
	// 	/* 5 */ test_gnl(fd, "xxxx\n");
	// 	/* 6 */ test_gnl(fd, NULL);
	// });

	printf("\n");
}