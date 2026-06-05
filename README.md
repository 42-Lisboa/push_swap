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
- [ ] Move reduction and efficiency tweaking (Targeting < 5500 moves for 500)
- [ ] Radix Sort implementation (Bitwise) for ultimate efficiency on 500 numbers
- [ ] Implement adaptive strategy based on the stack disorder index
- [ ] Create and implement logic for bench flag
- [ ] Implement new Makefile
- [ ] Check all files

## Development History & Last Changes

**Phase 1: Project Setup & Parsing**
- [x] Project initialization and initial data structure setup *by jalves & jpastolfi*
- [x] Implemented parsing logic, flags struct (`t_flags`), and edge case validation (e.g., `-`, `+`, `--adap`) *by jalves & jpastolfi*
- [x] Fixed syntax errors (`ft_strlen` brace) and refactored string/number conversion using `printf_fd` and a custom `atol` *by jalves*

**Phase 2: Stack Operations Implementation**
- [x] Implemented `push` (`pa`, `pb`) operations and integrated `capacity` into data structures *by jpastolfi*
- [x] Implemented `swap` operations with static functions for cleaner code *by jalves*
- [x] Implemented `rotate` and `reverse rotate` operations *by jalves & jpastolfi*
- [x] Added detailed comments to all stack operations *by jpastolfi*

**Phase 3: Dispatcher & Simple Algorithm (Selection Sort & Small Stacks)**
- [x] Created the dispatcher logic to route algorithms based on stack size *by jpastolfi*
- [x] Developed the `strategy_utils` for small stack sorting (2 to 5 numbers) *by jpastolfi*
- [x] Built the initial logic, merged selection sort concepts, and finished the `strategy_simple` algorithm *by jalves & jpastolfi*
- [x] Set up the testing environment for small stacks and performance checks (100/500 numbers) *by jalves*

**Phase 4: Medium Algorithm (Bucket Sort)**
- [x] Added custom `ft_sqrt` function to `libft` for dynamic chunk size calculations *by jalves*
- [x] Drafted initial logic for chunk sorting within `strategy_medium.c` *by jpastolfi*
- [x] Refactored `strategy_medium` and implemented move-reduction logic to improve the overall number of steps *by jalves*
- [x] Created and fixed functions to calculate stack disorder and adjusted return types *by jpastolfi*
- [x] Fixed Norminette issues across the algorithm logic *by jpastolfi*

**Phase 5: Complex Algorithm (Radix Sort Prep)**
- [x] Implemented `indexation` (Coordinate Compression) specifically for the Radix complex algorithm *by jalves*
- [x] Fixed and summarized README for better project tracking and understanding *by jalves*
- [x] Added detailed comments to all strategy_medium operations *by jalves*
- [x] Checked norminette on all files *by jalves*

---
*Jonathan Alves & Joao Astolfi — Programming Students @ 42*