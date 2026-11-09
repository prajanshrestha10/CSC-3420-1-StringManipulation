# CharCraft - C-String Workshop (3CS)

## Overview
CharCraft is a menu-driven C++ console application designed to demonstrate lower-level C-style string manipulation using `char*` pointers and the `<cstring>` standard library functions. The program allows users to dynamically allocate memory (`new[]` and `delete[]`) and perform key string operations without relying on `std::string` for storage or processing.

## Requirements & Environment
- **Compiler:** `g++` (supports C++11 or higher)
- **Environment:** Linux / POSIX terminal
- **Build Tool:** `make`

## Project Structure
- `StringManipulation.h`: Header file declaring the `StringManipulation` utility class and its member functions.
- `StringManipulation.cpp`: Implementation file containing function logic using standard `<cstring>` functions (`strcmp`, `strncmp`, `strcpy`, `strcat`, `strlen`, `strtok`).
- `StringManipulationTest.cpp`: Driver program containing the main function, menu interface, and user input handlers.
- `Makefile`: Simple build script to compile the project and clean up build artifacts.

## String Operations Implemented
1. **Compare two strings (`strcmp`)**: Compares two full C-strings lexicographically.
2. **Compare up to N characters (`strncmp`)**: Compares up to $N$ characters of two C-strings.
3. **Copy a string (`strcpy`)**: Allocates memory dynamically for a new copy of a C-string.
4. **Append a string (`strcat`)**: Concatenates two C-strings into a newly allocated buffer.
5. **Find length of a string (`strlen`)**: Determines the character count of a string excluding the null terminator.
6. **Tokenize and reverse word order (`strtok`)**: Splits a input sentence by whitespace and reconstructs it in reverse word order.

## Dynamic Memory Strategy
- All input strings are copied into dynamically allocated `char*` arrays using `new[]`.
- Operations returning new strings allocate exact buffer lengths plus one extra byte for the null terminator (`\0`).
- Every dynamically allocated buffer is explicitly deallocated using `delete[]` in `StringManipulationTest.cpp` after use to guarantee zero memory leaks.

## Compilation and Execution

### Build the application
To compile the source code into an executable named `CharCraft`:
```bash
make
```

### Run the application
To launch the program:
```bash
./CharCraft
```

### Record Terminal Execution
To create the required script execution output file:
```bash
script output.txt
./CharCraft
# Run through the menu options (1-6) and exit with 0
exit
```

### Clean up build files
To delete the compiled CharCraft executable:
```bash
make clean
```
