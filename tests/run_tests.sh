#!/bin/bash

# Clean and rebuild the project
make re

# Compile the test runner
# We need to compile test_swap.c with operations/swap.c and include the necessary headers
# Assuming libft is needed as well, we link against it
cc -g tests/test_swap.c operations/swap.c -I . -I libft_lib -L libft_lib -lft -o test_swap

# Run the tests
if [ -f ./test_swap ]; then
    echo "Running tests..."
    ./test_swap
else
    echo "Compilation failed!"
    exit 1
fi
