#!/bin/bash

# Configuration
LIMIT=12
PROGRAM="./push_swap"
CHECKER="./checker_linux"

echo "--- Testing all 24 permutations of 4 numbers ---"

# Generate permutations of 1 2 3 4
python3 -c "import itertools; print('\n'.join(' '.join(map(str, p)) for p in itertools.permutations(range(1, 5))))" | while read -r nums; do
    
    # Run push_swap and count lines
    ops=$($PROGRAM $nums)
    count=$(echo "$ops" | grep -v '^$' | wc -l)
    
    # Run checker
    check_res=$(echo "$ops" | $CHECKER $nums)

    if [ "$check_res" != "OK" ]; then
        echo "❌ ERROR: [$nums] -> Checker said $check_res"
    elif [ "$count" -gt "$LIMIT" ]; then
        echo "⚠️  OVER LIMIT ($count lines): [$nums]"
    else
        # Optional: Print all results for 4 numbers since there are only 24
        echo "OK ($count moves): $nums"
    fi
done

echo "--- Done ---"