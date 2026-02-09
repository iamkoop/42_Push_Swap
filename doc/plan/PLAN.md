# Master Execution Manifesto: Push Swap

## 1. Technical Foundation
**Algorithm Strategy:**
-   **Primary Algorithm:** Turk Algorithm.
    -   Focus: Efficiently push from A to B in descending order (or chunks), then push back to A ensuring correct position.
    -   Target Complexity: Aiming for < 700 operations (100 numbers) and < 5500 operations (500 numbers).
-   **Data Structure:** Circular Doubly Linked List.
    -   Why: Constant time access to head/tail for `r` and `rr` operations. efficient insertion/deletion for `p` operations.

**Constraints & Baseline:**
-   **Allowed Functions:** `write`, `malloc`, `free`, `exit`.
-   **Forbidden:** Global variables (usually), `printf` (user choice generally to avoid it for speed/simplicity, strict project adherence to `write`), `libft` allowed.
-   **Error Handling:** Must output "Error" followed by a newline to Standard Error (2) for any invalid input (duplicates, non-integers, overflow).
-   **Memory Management:** 0 leaks tolerated. Full cleanup required on exit/error.

## 2. Implementation Map
**A. Supporting Infrastructure (The "Boring" Stuff)**
-   **Parsing Module:** *Status: Mostly Complete.* Focus on leak-proofing error paths.
-   **Stack Operations:** Standard 42 set (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).
-   **Stack Utilities:** `new_node`, `add_back`, `stack_size`, `free_stack`, `print_error`.

**B. Core Logic (The Turk Engine)**
-   **The Attribute Calculator:** Function to iterate stack and update `target_node` and `push_cost` for every node in Stack A.
-   **The Move Executor:** Function to execute the cheapest move (sync routines `rr`/`rrr` first, then remainder).
-   **The Sort Controller:** Main loop: Push to B -> Calculate Costs -> Move Cheapest -> Repeat -> Push back to A.

## 3. The Pitfall Registry
**High Risk:**
-   **Logic:** "Cheapest Move" calculation off-by-one errors.
-   **Edge Case:** 3 random numbers (hardcode this?), 5 random numbers.
-   **Memory:** Leaks when `malloc` fails mid-parsing or during `split`.


## 4. Verification & Unit Testing
**Automated Loop:**
-   **Script:** `for i in {1..100}; do ARG=$(shuf -i 0-1000 -n 100); ./push_swap $ARG | ./checker_linux $ARG; done`
-   **Operation Count Check:** Same script but pipe to `wc -l` to ensure we stay under the limit (700 for 100, 5500 for 500).

**Edge Case Gauntlet:**
-   Empty input.
-   Non-numeric input (`a`, `123a`, plain ` `).
-   `INT_MAX` / `INT_MIN`.
-   Duplicates (`1 2 2 3`).
-   Already sorted (`1 2 3`).
-   Reverse sorted (`3 2 1`).

## 5. Retro-Timeline (5-Day Sprint)
-   **Day 1:** Finalize Parsing (Leak Proofing) + Initialize Stack Structure.
-   **Day 2:** Operations (`sa`, `pb`, etc.) + Utils + Hardcoded Sort (3/5).
-   **Day 3:** TURK CORE: Cost Calculation + Target Node Finding.
-   **Day 4:** TURK CORE: Move Executor + Sync Optimization (`rr`/`rrr`).
-   **Day 5:** The Gauntlet (500 runs) + Norminette + Peer Defense Prep.

## 6. The "Peer-Defense" Cheat Sheet
**Q: Why a Circular Doubly Linked List?**
**A:** "Efficiency. Standard operations like `rra` (Reverse Rotate) require moving the last node to the front. With a circular DLL, `tail->next` is `head`, and `head->prev` is `tail`. This makes stack rotations O(1) constant time with no traversal needed."

**Q: Show me your overflow check.**
**A:** "In `input_check.c`, inside `valid_num`. After `ft_atol`, I explicitly check `if (num > INT_MAX || num < INT_MIN)`. This prevents internal overflow before adding to the stack."

**Q: Explain the Turk Algorithm.**
**A:** "It's a 'Push-Sort-Paste' strategy. I push everything to B (cheaply) leaving 3 nodes in A. I sort A. Then, I calculate the 'cheapest' node in B to push back to A, aiming for its correct sorted position, exploiting the fact that B is roughly sorted descending."


