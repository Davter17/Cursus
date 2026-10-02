# Piscine - 42 School Bootcamp

A comprehensive collection of C programming exercises completed during the 42 School Piscine bootcamp, covering fundamental programming concepts to advanced problem-solving.

## Overview

The Piscine is an intensive 4-week bootcamp that serves as the introduction to 42's curriculum. This repository contains all completed exercises, rushes, and the final BSQ project, demonstrating progressive mastery of C programming, algorithms, and collaborative problem-solving.

## Contents

### C Modules (C00-C13)
Progressive exercises covering C programming fundamentals:

- **C00**: Basic functions, loops, and output operations
- **C01**: Pointers and memory addresses
- **C02**: String manipulation and character handling
- **C03**: String comparison and concatenation
- **C04**: Number conversion and output
- **C05**: Iteration and recursion (factorials, Fibonacci, primes)
- **C06**: Command-line arguments
- **C07**: Memory allocation with malloc
- **C08**: Header files and preprocessor directives
- **C09**: Library creation and code organization
- **C10**: File handling and standard streams
- **C11**: Linked lists and data structures
- **C12**: Advanced data structures
- **C13**: Binary search trees

### Rush Projects
Team-based collaborative projects (48-hour challenges):

- **Rush00**: Pattern drawing with ASCII characters
- **Rush01**: Skyscraper puzzle solver (4x4 grid logic)
- **Rush02**: Number-to-words converter with dictionary

### Shell Modules (Shell00-Shell01)
Unix shell commands and scripting exercises

### BSQ - Biggest Square
Final project: Find and display the largest square of empty spaces in a map, avoiding obstacles.

## Project Structure

```
Piscine/
├── Shell00-Shell01/     # Shell command exercises
├── C00-C13/              # C programming exercises
│   ├── ex00-ex13/       # Individual exercises
│   └── *.pdf            # Subject files
├── Rush00/              # ASCII pattern drawing
│   └── ex00/           # Multiple rush implementations
├── Rush01/              # Skyscraper puzzle solver
│   └── ex00/           # Backtracking solution
├── Rush02/              # Number to words converter
│   └── ex00/           # Dictionary-based solution
├── BSQ/                 # Final project
│   ├── main.c          # Entry point
│   ├── processing.c    # Map processing
│   ├── solve_square.c  # Square finding algorithm
│   ├── to_matrix.c     # Map conversion
│   ├── matrix_size.c   # Dimension calculation
│   ├── free_resources.c # Memory management
│   └── Makefile        # Build configuration
└── README.md           # This file
```

## Compilation

### BSQ Project
```bash
cd BSQ
make
```

### Rush01 (Skyscraper Puzzle)
```bash
cd Rush01/ex00
gcc -Wall -Wextra -Werror -o rush-01 *.c
```

### Rush02 (Number to Words)
```bash
cd Rush02/ex00
gcc -Wall -Wextra -Werror -o rush-02 *.c
```

### Individual Exercises
```bash
cd C00/ex00
gcc -Wall -Wextra -Werror ft_putchar.c
```

## Usage

### BSQ
```bash
# With file argument
./bsq map.txt

# With multiple files
./bsq map1.txt map2.txt

# From stdin
cat map.txt | ./bsq
```

### Rush01 (Skyscraper Puzzle)
```bash
# Input format: 16 space-separated values (1-4)
# Order: col_up(4), col_down(4), row_left(4), row_right(4)
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

### Rush02 (Number to Words)
```bash
# With default dictionary
./rush-02 12345

# With custom dictionary
./rush-02 numbers.dict 12345
```

## Code Quality

- All code complies with 42 school's norminette standards
- No memory leaks (verified with valgrind)
- Proper error handling
- Clean code organization
- Comprehensive test coverage

## Technical Highlights

### Memory Management
- Careful allocation and deallocation
- No memory leaks or double frees
- Proper cleanup in all error paths

### Algorithms
- Backtracking for constraint satisfaction (Rush01)
- Dynamic programming approach for largest square (BSQ)
- Efficient string parsing and processing

### Error Handling
- Input validation
- File I/O error checking
- Memory allocation failure handling
- Graceful error messages

## Requirements

- GCC compiler
- Make (for BSQ)
- Unix-like environment (Linux, macOS, or WSL)
- norminette (for 42 students)

## Testing

### Memory Testing
```bash
# Test BSQ for memory leaks
valgrind --leak-check=full ./bsq map.txt

# Test Rush02
valgrind --leak-check=full ./rush-02 12345
```

### Norminette
```bash
# Check all files
norminette C00/ C01/ C02/ ...
norminette Rush00/ Rush01/ Rush02/
norminette BSQ/
```

## Learning Outcomes

- **C Programming**: Mastery of pointers, memory management, and data structures
- **Algorithms**: Problem-solving and algorithmic thinking
- **Unix Environment**: Shell commands, file systems, and process management
- **Collaboration**: Team-based rush projects under time pressure
- **Code Quality**: Writing clean, maintainable, and efficient code

## Author

- **Mario Pico** (@Davter17)

## License

This project is part of the 42 school curriculum and follows its academic guidelines.
