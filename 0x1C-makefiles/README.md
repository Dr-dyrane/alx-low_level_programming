# ALX Software Engineering Program - 0x1C Makefiles

This repository contains a series of tasks related to Makefiles in the context of C programming. The tasks are part of the ALX Software Engineering Program and are designed to help participants understand and utilize Makefiles effectively in managing C projects.

## Table of Contents

1. [Introduction](#introduction)
2. [Tasks](#tasks)
3. [Getting Started](#getting-started)
4. [How to Use](#how-to-use)
5. [Files and Directories](#files-and-directories)
6. [Dependencies](#dependencies)
7. [Contributing](#contributing)
8. [License](#license)
9. [Author](#author)

## Introduction

Makefiles are essential tools for automating the build process of software projects. They define rules for compiling source files, handling dependencies, and generating executable binaries. This project covers various tasks that will guide participants through creating Makefiles to manage C programs efficiently.

## Tasks

The project consists of the following tasks:

1. `0-Makefile`: Creating a basic Makefile for building an executable named `school` using two C source files.
2. `1-Makefile`: Enhancing the previous Makefile by using variables to specify the compiler and source files.
3. `2-Makefile`: Extending the Makefile to include object files and the final executable name as variables.
4. `3-Makefile`: Adding rules for cleaning temporary files, object files, and the executable, along with a recompilation rule.
5. `4-Makefile`: Further enhancing the Makefile by including the `CFLAGS` variable to store compiler flags.
6. `5-island_perimeter.py`: A Python script to calculate the perimeter of an island represented by a grid.
7. `100-Makefile`: An advanced version of the Makefile with specific constraints and limitations to follow.

### Task 0: 0-Makefile

```make
# This Makefile is used to build the 'school' executable from 'main.c' and 'school.c' source files.

# Compiler variable
CC := gcc

# Source files
SRC := main.c school.c

# Rule for the 'all' target
all:
	$(CC) $(SRC) -o school

# Clean rule: remove the generated executable
clean:
	rm -f school
```

Explanation:

- This Makefile is used to compile the `school` executable from the `main.c` and `school.c` source files.
- `CC := gcc` sets the compiler variable `CC` to `gcc`.
- `SRC := main.c school.c` sets the source files to `main.c` and `school.c`.
- The `all` rule is used to build the `school` executable. It runs the command `gcc main.c school.c -o school` to compile and link the source files into an executable called `school`.
- The `clean` rule removes the generated executable (`school`) by running `rm -f school`.

### Task 1: 1-Makefile

```make
# Makefile for building the 'school'
# executable using the specified compiler and source files.

# Compiler variable
CC = gcc

# Source files variable
SRC = main.c school.c

# Rule for the 'all' target
# This rule builds the 'school' executable by compiling the source files
# using the specified compiler.
all: $(SRC)
	$(CC) $(SRC) -o school
```

Explanation:

- This Makefile is similar to Task 0, but it uses variables for the compiler (`CC`) and source files (`SRC`).
- The `CC = gcc` sets the compiler variable `CC` to `gcc`.
- The `SRC = main.c school.c` sets the source files to `main.c` and `school.c`.
- The `all` rule is used to build the `school` executable. It has a dependency on the source files `$(SRC)`, which means it will run the rule only if the source files have been updated. It compiles and links the source files into an executable called `school`.

### Task 2: 2-Makefile

```make
# Makefile for building the 'school' executable from the specified source files using the specified compiler.

# Compiler variable
CC = gcc

# Source files variable
SRC = main.c school.c

# Object files variable
OBJ = $(SRC:.c=.o)

# Target executable name
NAME = school

# Rule for the 'all' target
all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
```

Explanation:

- This Makefile is an extension of Task 1 and introduces more variables: `OBJ` and `NAME`.
- The `OBJ` variable is derived from the `SRC` variable using the `$(SRC:.c=.o)` syntax, which means it replaces the `.c` extension with `.o`. So, `OBJ` will be set to `main.o school.o`.
- The `NAME` variable specifies the name of the executable, which is set to `school`.
- The `all` rule is used to build the `school` executable. It has a dependency on the object files `$(OBJ)`, which means it will run the rule only if the object files have been updated. It compiles and links the object files into an executable called `school`.

### Task 3: 3-Makefile

```make
# Makefile for building the 'school' executable from the specified source files using the specified compiler.

# Compiler variable
CC = gcc

# Source files variable
SRC = main.c school.c

# Object files variable
OBJ = $(SRC:.c=.o)

# Target executable name
NAME = school

# Rule for the 'all' target
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

# Clean rule: deletes all Emacs and Vim temporary files along with the executable
clean:
	rm -f *~ $(NAME)

# Oclean rule: deletes the object files
oclean:
	rm -f $(OBJ)

# Fclean rule: deletes all Emacs and Vim temporary files, the executable, and the object files
fclean: clean oclean

# Re rule: forces recompilation of all source files
re: fclean all
```

Explanation:

- This Makefile introduces more rules: `clean`, `oclean`, `fclean`, and `re`.
- The `all` rule is the same as in Task 2, building the `school` executable from the object files.
- The `$(NAME): $(OBJ)` is an explicit rule for building the `school` executable from the object files. It states that the `$(NAME)` target depends on the `$(OBJ)` dependency, meaning it will only run the rule if the object files have been updated. It compiles and links the object files into an executable called `school`.

- The `clean` rule removes Emacs and Vim temporary files (`*~`) and the `school` executable.

- The `oclean` rule removes the object files (`$(OBJ)`).

- The `fclean` rule combines the `clean` and `oclean` rules, effectively removing all Emacs and Vim temporary files, the `school` executable, and the object files.

- The `re` rule is used to force recompilation of all source files by running the `fclean` and `all` rules.

### Task 4: 4-Makefile

```make
# Makefile for building the 'school' executable from the specified source files using the specified compiler.

# Compiler variable
CC = gcc

# Source files variable
SRC = main.c school.c

# Object files variable
OBJ = $(SRC:.c=.o)

# Target executable name
NAME = school

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic

# Rule for the 'all' target
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Clean rule: deletes all Emacs and Vim temporary files along with the executable
clean:
	rm -f *~ $(NAME)

# Oclean rule: deletes the object files
oclean:
	rm -f $(OBJ)

# Fclean rule: deletes all Emacs and Vim temporary files, the executable, and the object files
fclean: clean oclean

# Re rule: forces recompilation of all source files
re: fclean all
```

Explanation:

- This Makefile is an extension of Task 3 and introduces the `CFLAGS` variable, which holds compiler flags (`-Wall -Werror -Wextra -pedantic`).
- The `all` rule is the same as in Task 3, building the `school` executable from the object files.
- The `$(NAME): $(OBJ)` rule is the same as in Task 3, compiling and linking the object files into an executable called `school`.
- The `CFLAGS = -Wall -Werror -Wextra -pedantic` sets the `CFLAGS` variable

to the specified compiler flags.

- The `clean`, `oclean`, `fclean`, and `re` rules are the same as in Task 3.

### Task 5: 5-island_perimeter.py

Explanation:

- This file contains a Python function called `island_perimeter`.
- The function takes a 2D list (`grid`) representing an island, where 0 represents water and 1 represents land.
- It calculates the perimeter of the island based on the number of land cells and their arrangement.
- The function first initializes variables `width`, `height`, `edges`, and `size` to calculate the perimeter.
- It then iterates through the `grid` and checks if each cell is land (1). If it is land, it increments the `size` variable by 1 and checks its adjacent cells to count the number of edges (`edges`) surrounding the land cell.
- Finally, it returns the computed perimeter using the formula `size * 4 - edges * 2`.

### Task 6: 100-Makefile

```make
# Advanced Makefile for building the 'school' executable from the specified source files using the specified compiler.

# Compiler variable
CC = gcc

# Source files variable
SRC = main.c school.c

# Object files variable
OBJ = $(SRC:.c=.o)

# Target executable name
NAME = school

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic

# All phony targets
.PHONY: all clean oclean fclean re

# Rule for the 'all' target
all: m.h $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Clean rule: deletes all Emacs and Vim temporary files along with the executable
clean:
	$(RM) *~ $(NAME)

# Oclean rule: deletes the object files
oclean:
	$(RM) $(OBJ)

# Fclean rule: deletes all Emacs and Vim temporary files, the executable, and the object files
fclean: clean oclean

# Re rule: forces recompilation of all source files
re: fclean all
```

Explanation:

- This Makefile is an advanced version of Task 4, implementing additional rules and restrictions.
- The `CC`, `SRC`, `OBJ`, `NAME`, `CFLAGS`, and `.PHONY` directives are the same as in Task 4.

- The `.PHONY: all clean oclean fclean re` directive declares these targets as phony, which means they are not file targets but rather actions.

- The `all` rule is the same as in Task 4, building the `school` executable from the object files. It has a dependency on `m.h` (the header file) and the object files `$(OBJ)`.

- The `clean` rule uses `$(RM)` to remove Emacs and Vim temporary files (`*~`) and the `school` executable.

- The `oclean` rule uses `$(RM)` to remove the object files (`$(OBJ)`).

- The `fclean` rule combines the `clean` and `oclean` rules, effectively removing all Emacs and Vim temporary files, the `school` executable, and the object files.

- The `re` rule is used to force recompilation of all source files by running the `fclean` and `all` rules.

Note: The `m.h` dependency in the `all` rule ensures that the Makefile does not compile if the header file `m.h` is missing in the current directory.

## Getting Started

To get started with this project, you will need:

- An Ubuntu 20.04 LTS operating system.
- GCC version 9.3.0.
- GNU Make version 4.2.1.

## How to Use

To use this repository, follow these steps:

1. Clone the repository:

```
git clone https://github.com/Dr-dyrane/alx-low_level_programming.git
```

2. Navigate to the `0x1C-makefiles` directory:

```
cd alx-low_level_programming/0x1C-makefiles
```

3. Complete the tasks as outlined in each individual task file.

4. Compile the C programs and run the Makefiles as demonstrated in each task.

## Files and Directories

The repository is organized as follows:

- `0x1C-makefiles`: The main directory containing the Makefile tasks.
- `0x1C-makefiles/0-Makefile`: Task 0 - Basic Makefile.
- `0x1C-makefiles/1-Makefile`: Task 1 - Enhanced Makefile with Variables.
- `0x1C-makefiles/2-Makefile`: Task 2 - Makefile with Object Files.
- `0x1C-makefiles/3-Makefile`: Task 3 - Makefile with Cleaning Rules.
- `0x1C-makefiles/4-Makefile`: Task 4 - Makefile with Compiler Flags.
- `0x1C-makefiles/5-island_perimeter.py`: Task 5 - Python script for calculating island perimeter.
- `0x1C-makefiles/100-Makefile`: Task 6 - Advanced Makefile.

## Dependencies

This project does not have any external dependencies other than the specified versions of GCC and GNU Make.

## Contributing

Contributions to this repository are not allowed as per the project requirements.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author

This project is authored by Alexander Udeogaranya as part of the ALX Software Engineering Program. For any inquiries or feedback, please contact me via [GitHub](https://github.com/Dr-dyrane).
