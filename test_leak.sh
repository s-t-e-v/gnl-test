cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=10000000 ../get_next_line.c ../get_next_line_utils.c test_leak.c -o tests -I../
valgrind ./tests