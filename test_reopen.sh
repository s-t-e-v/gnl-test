cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=500 ../get_next_line.c ../get_next_line_utils.c test_reopen.c -o tests -I../
valgrind ./tests