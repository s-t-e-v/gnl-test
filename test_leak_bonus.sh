cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=10000000 ../get_next_line_bonus.c ../get_next_line_utils_bonus.c test_leak_bonus.c -o tests -I../
valgrind ./tests