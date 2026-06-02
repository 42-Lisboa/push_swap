# push_swap 🔄

> **🚧 Work In Progress 🚧**

A 42 school algorithmic project focused on sorting data on a stack with a limited set of instructions, using the absolute minimum number of moves. 

## Current Status
- [x] Input parsing and error validation, also for flags
- [x] Data structure implementation
- [x] Stack operations implementation (`sa`, `pa`, `ra`, `rra`, etc.)
- [ ] Small sort logic (3 to 5 numbers)
- [ ] Make the algorithms return the number of operations
- [ ] Large sort algorithm implementation (optimizing for 100 and 500 numbers)
- [ ] Move reduction and efficiency tweaking

## Last Changes
- [x] Multi-flag parsing and `t_flags` state implementation *by jalves*
- [x] Strict validation against duplicate or conflicting flags *by jalves*
- [x] Modularized parse_flags logic to respect the 25-line maximum rule *by jalves*
- [x] Fixed `argc`/`argv` offset bug in `is_valid_number` call after flag parsing *by jastolfi*
- [x] Added `dispatcher` with function pointer table routing to strategy sort stubs *by jastolfi*
- [x] Declared `dispatcher` in `utils.h` *by jastolfi*
- [x] Finished main code for ops_push - lacks integration with capacity or other strategy to handle this edge case *by jalves*
- [x] Created static function to make ops_swap.c cleaner *by jalves*

---
*Jonathan Alves & Joao Astolfi — Programming Students @ 42*