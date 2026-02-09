#!/bin/bash

# Ensure we are in the project root
cd "$(dirname "$0")/.."

# Clean and rebuild the project
make re

# Compile the test runner
# Output binary to tests/ directory to keep root clean
cc -g tests/test_swap.c operations/swap.c -I . -I libft_lib -L libft_lib -lft -o tests/test_swap

# Run the tests
if [ -f tests/test_swap ]; then
    echo "Running tests..."
    ./tests/test_swap
else
    echo "Compilation failed!"
    exit 1
fi
