# push_swap 🔄

> **🚧 Work In Progress 🚧**

A 42 school algorithmic project focused on sorting data on a stack with a limited set of instructions, using the absolute minimum number of moves.

## Current Status
- [x] Input parsing and error validation, also for flags
- [x] Data structure implementation
- [x] Stack operations implementation (`sa`, `pa`, `ra`, `rra`, etc.)
- [x] Small sort logic (2 to 5 numbers)
- [x] Make the algorithms return the exact number of operations cleanly
- [x] Large sort algorithm implementation on medium strategy (Bucket Sort)
- [x] Move reduction and efficiency tweaking (Targeting < 5500 moves for 500)
- [x] Radix Sort implementation (Bitwise) for ultimate efficiency on 500 numbers
- [x] Implement adaptive strategy based on the stack disorder index
- [ ] Create and implement logic for bench flag
- [ ] Implement new Makefile
- [ ] Check all files

## Development History & Last Changes

**Phase 1: Project Setup & Parsing**
- [x] 🟣 Project initialization and initial data structure setup
- [x] 🟣 Implemented parsing logic, flags struct (`t_flags`), and edge case validation (e.g., `-`, `+`, `--adap`)
- [x] 🟢 Fixed syntax errors (`ft_strlen` brace) and refactored string/number conversion using `printf_fd` and a custom `atol`

**Phase 2: Stack Operations Implementation**
- [x] 🔵 Implemented `push` (`pa`, `pb`) operations and integrated `capacity` into data structures
- [x] 🟢 Implemented `swap` operations with static functions for cleaner code
- [x] 🟣 Implemented `rotate` and `reverse rotate` operations
- [x] 🔵 Added detailed comments to all stack operations

**Phase 3: Dispatcher & Simple Algorithm (Selection Sort & Small Stacks)**
- [x] 🔵 Created the dispatcher logic to route algorithms based on stack size
- [x] 🔵 Developed the `strategy_utils` for small stack sorting (2 to 5 numbers)
- [x] 🟣 Built the initial logic, merged selection sort concepts, and finished the `strategy_simple` algorithm
- [x] 🟢 Set up the testing environment for small stacks and performance checks (100/500 numbers)

**Phase 4: Medium Algorithm (Bucket Sort)**
- [x] 🟢 Added custom `ft_sqrt` function to `libft` for dynamic chunk size calculations
- [x] 🔵 Drafted initial logic for chunk sorting within `strategy_medium.c`
- [x] 🟢 Refactored `strategy_medium` and implemented move-reduction logic to improve the overall number of steps
- [x] 🔵 Created and fixed functions to calculate stack disorder and adjusted return types
- [x] 🟢 Added detailed comments to all `strategy_medium` operations
- [x] 🔵 Fixed Norminette issues across the algorithm logic
- [x] 🟢 Refactored logic of min and max from strategy_medium to and array of integers with two numbers, so it is correct with the norm about limit parameters on function

**Phase 5: Complex Algorithm (Radix Sort)**
- [x] 🟢 Implemented `indexation` (Coordinate Compression) specifically for the Radix complex algorithm
- [x] 🟢 Fixed norminette and summarized README for better project tracking and understanding
- [x] 🟢 Implemented new function get_max_bits
- [x] 🔵 Refactored `push_swap.c` and main execution flow to prepare integration with complex and adaptive strategies
- [x] 🟢 Continued Radix Sort groundwork by implementing bit-count calculation (`get_max_bits`) and integrating the required structures for bitwise processing

**Phase 6: Adaptive Algorithm**
- [x] 🔵 Created function to calculate the disorder of the array
- [x] 🔵 Expanded adaptive strategy logic and improved algorithm selection preparation based on stack disorder analysis
- [x] 🟢 Refactored adaptive strategy implementation and fixed Norminette issues across related files

**Phase 7: Benchmark Functionality**
- [x] 🟣 Implemented main logic for benchmark functionality. Changed operations logic and created struct to keep track of operations count
- [x] 🟣 Implemented new function on libft to print also float numbers
- [x] 🟣 Finished benchmark main implemetation
- [x] 🟢 Fixed norminette in all of the files, also replaced some variables names
- [ ] ⚫ Change ops logic to hide functions when bench is off
- [ ] ⚫ Create Makefile
- [ ] ⚫ Test final program on project official testers
- [ ] ⚫ Check all files: names, comments and norminette

---
### 👨‍💻 Authors & Contributions
🟢 **Jonathan Alves** (`jalves`)
🔵 **João Astolfi** (`jpastolfi`)
🟣 **Pair Programming / Both**

*Programming Students @ 42*