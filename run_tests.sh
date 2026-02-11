make -C libft_lib
gcc -g -c -I. -Ilibft_lib initial_stack_creation.c -o initial_stack_creation.o
nm initial_stack_creation.o | grep create_initial_stack
gcc -g -c -I. -Ilibft_lib input_conversion.c -o input_conversion.o
gcc -g -c -I. -Ilibft_lib input_sort.c -o input_sort.o
gcc -g -c -I. -Ilibft_lib operations/swap.c -o operations/swap.o
gcc -g -c -I. -Ilibft_lib operations/rotate.c -o operations/rotate.o
gcc -g -I. -Ilibft_lib tests/test_swap.c initial_stack_creation.o input_conversion.o input_sort.o operations/swap.o libft_lib/libft.a -o tests/test_swap_bin
./tests/test_swap_bin
gcc -g -I. -Ilibft_lib tests/test_rotate.c initial_stack_creation.o input_conversion.o input_sort.o operations/rotate.o libft_lib/libft.a -o tests/test_rotate_bin
./tests/test_rotate_bin
gcc -g -c -I. -Ilibft_lib operations/reverse_rotate.c -o operations/reverse_rotate.o
gcc -g -I. -Ilibft_lib tests/test_reverse_rotate.c initial_stack_creation.o input_conversion.o input_sort.o operations/rotate.o operations/reverse_rotate.o libft_lib/libft.a -o tests/test_reverse_rotate_bin
./tests/test_reverse_rotate_bin
./tests/test_reverse_rotate_bin
gcc -g -c -I. -Ilibft_lib sort.c -o sort.o
gcc -g -I. -Ilibft_lib tests/test_sort_3.c initial_stack_creation.o input_conversion.o input_sort.o operations/rotate.o operations/swap.o operations/reverse_rotate.o sort.o libft_lib/libft.a -o tests/test_sort_3_bin
./tests/test_sort_3_bin
#rm tests/test_swap_bin tests/test_rotate_bin tests/test_reverse_rotate_bin tests/test_sort_3_bin *.o operations/*.o
