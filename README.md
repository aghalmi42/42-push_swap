# 🔄 Push_swap - Project 42

A data-sorting project using two stacks and a limited set of operations, with the goal of finding the most efficient algorithm.

## 📋 Table of Contents

- Description
- Rules
- Operations
- Installation
- Usage
- Algorithms
- Project Structure
- Compilation
- Examples

## 📝 Description

**Push_swap** is a project from 42 School that consists of sorting integers using two stacks (`a` and `b`) and a restricted set of operations.
The goal is to sort stack `a` in ascending order using the minimum possible number of operations.

### Objectives

- ✅ Sort a sequence of integers
- ✅ Use two stacks (`a` and `b`)
- ✅ Optimize the number of operations
- ✅ Handle input errors properly

## 📏 Rules

1. At the start, stack `a` contains a random amount of integers (positive and/or negative) with no duplicates
2. Stack `b` is empty
3. The goal is to sort the values in stack `a` in ascending order
4. You can only use a limited set of operations

## 🔧 Operations

### Push
- `pa` : **push a** - Take the top element of `b` and push it onto `a`
- `pb` : **push b** - Take the top element of `a` and push it onto `b`

### Swap
- `sa` : **swap a** - Swap the first two elements at the top of stack `a`
- `sb` : **swap b** - Swap the first two elements at the top of stack `b`
- `ss` : Perform `sa` and `sb` simultaneously

### Rotate
- `ra` : **rotate a** - Shift all elements of stack `a` up by one
- `rb` : **rotate b** - Shift all elements of stack `b` up by one
- `rr` : Perform `ra` and `rb` simultaneously

### Reverse Rotate
- `rra` : **reverse rotate a** - Shift all elements of stack `a` down by one
- `rrb` : **reverse rotate b** - Shift all elements of stack `b` down by one 
- `rrr` : Perform `rra` and `rrb` simultaneously

## 🚀 Installation

```bash
# Clone the repository
git clone https://github.com/bhyant/42-Push_swap.git
cd 42-Push_swap

# Compile the project
make
```

## 💻 Usage

```bash
# Sort numbers
./push_swap 4 67 3 87 23

# With a string of numbers
./push_swap "4 67 3 87 23"

# Combine both
./push_swap 4 "67 3" 87 23
```

### Error Handling

The program prints `Error` and returns an error code in the following cases:

- ❌ Non-numeric arguments
- ❌ Numbers outside the range of an `int`
- ❌ Duplicate values
- ❌ No arguments provided

```bash
./push_swap abc        # Error
./push_swap 1 2 3 2    # Error (duplicate)
./push_swap            # Error (no arguments)
```

## 🧠 Algorithms

The project implements multiple sorting strategies depending on the number of elements:

### 🔹 2 elements
- Simple swap if needed

### 🔹 3 elements
- Optimized algorithm using at most 2 operations

### 🔹 4 elements
- Push the minimum to `b`
- Sort the remaining 3
- Push the minimum back to `a`

### 🔹 5 elements
- Push the 2 minimum values to `b`
- Sort the remaining 3
- Push the 2 values back to `a`

### 🔹 More than 5 elements: Turkish sort
- 42-based sorting algorithm

## 📁 Project Structure
```
42-Push_swap/
├── Makefile                    # Compilation file
├── README.md                   # This file
├── includes/
│   ├── push_swap.h             # Main header
│   └── get_next_line.h         # Header for get_next_line
├── mandatory/
│   └── *.c                      # All mandatory .c source files
```

## 🔨 Compilation

### Available Commands

```bash
make          # Compile the project
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Recompile everything
```

### Compilation Flags

```makefile
-Wall -Wextra -Werror    # All warnings treated as errors
-MMD -MP                  # Automatic dependency management
-g3                       # Debug information
```

## 📊 Examples

### Example 1 : 3 numbers
```bash
$ ./push_swap 2 1 3
sa
```

### Example 2 : 5 numbers
```bash
$ ./push_swap 5 4 3 2 1
rra
pb
rra
pb
ra
sa
pa
pa
```

### Example 3 : Using a string
```bash
$ ./push_swap "3 2 1 0"
sa
rra
sa
```

### Check the number of operations
```bash
$ ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
# Prints the number of operations used
```

## 🎯 Performance Targets

To achieve full points:

| Size |	Number of operations |
|------|-----------------------|
| 3	   | ≤ 3                   |
| 5	   | ≤ 12                  | 
| 100	 | ≤ 700 (5 pts)         |
| 100	 | ≤ 900 (4 pts)         |
| 100	 | ≤ 1100 (3 pts)        |
| 100	 | ≤ 1300 (2 pts)        |
| 100	 | ≤ 1500 (1 pt)         | 
| 500	 | ≤ 5500 (5 pts)        | 
| 500	 | ≤ 7000 (4 pts)        |
| 500	 | ≤ 8500 (3 pts)        |
| 500	 | ≤ 10000 (2 pts)       |
| 500	 | ≤ 11500 (1 pt)        |

## 📄 License

This project is part of the 42 School curriculum.
