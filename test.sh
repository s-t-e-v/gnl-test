cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=20 ../get_next_line.c ../get_next_line_utils.c test.c -o tests -I../
valgrind ./tests