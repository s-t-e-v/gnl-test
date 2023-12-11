cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=20 ../get_next_line_bonus.c ../get_next_line_utils_bonus.c test_bonus.c -o tests -I../
valgrind ./tests