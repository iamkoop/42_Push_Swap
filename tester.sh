#!/bin/bash

# Configuration
LIMIT=12
PROGRAM="./push_swap"
CHECKER="./checker_linux"

# Generate permutations of 1 2 3 4 5 and test them
python3 -c "import itertools; print('\n'.join(' '.join(map(str, p)) for p in itertools.permutations(range(1, 6))))" | while read -r nums; do
    # Get the operations from push_swap
    ops=$($PROGRAM $nums)
    
    # Count the number of lines (operations)
    # We use grep . to ensure we don't count empty lines if push_swap outputs nothing
    count=$(echo "$ops" | grep -v '^$' | wc -l)
    
    # Check with the provided checker
    check_res=$(echo "$ops" | $CHECKER $nums)

    if [ "$check_res" != "OK" ]; then
        echo "❌ FAILED: [$nums] -> Checker returned $check_res"
    elif [ "$count" -gt "$LIMIT" ]; then
        echo "⚠️  OVER LIMIT ($count): [$nums]"
    fi
done

echo "Testing complete."
