make -C libft_lib
gcc -g -c -I. -Ilibft_lib initial_stack_creation.c -o initial_stack_creation.o
nm initial_stack_creation.o | grep create_initial_stack
gcc -g -c -I. -Ilibft_lib input_conversion.c -o input_conversion.o
gcc -g -c -I. -Ilibft_lib input_sort.c -o input_sort.o
gcc -g -c -I. -Ilibft_lib operations/swap.c -o operations/swap.o
gcc -g -I. -Ilibft_lib tests/test_swap.c initial_stack_creation.o input_conversion.o input_sort.o operations/swap.o libft_lib/libft.a -o tests/test_swap_bin
./tests/test_swap_bin
#rm tests/test_swap_bin *.o operations/*.o
