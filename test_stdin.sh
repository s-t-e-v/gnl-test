cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=20 ../get_next_line_bonus.c ../get_next_line_utils_bonus.c test_stdin.c -o tests -I../
echo -e -n "This is line 1\nThis is line 2\nThis is line 3" | ./tests