# Dynamic Libraries

This repository contains the project created by [Alexander Udeogaranya](https://github.com/Dr-dyrane) as part of the ALX Software Engineering program. The project focuses on dynamic libraries in C and provides an understanding of what dynamic libraries are, how they work, how to create them, and how to use them. It also covers related topics such as environment variables, static libraries vs. dynamic libraries, and basic tools for working with dynamic libraries.

## Table of Contents

- [General Concepts](#general-concepts)
  - [Dynamic Libraries](#dynamic-libraries)
  - [Environment Variable `$LD_LIBRARY_PATH`](#environment-variable-ld_library_path)
  - [Static Libraries vs. Dynamic Libraries](#static-libraries-vs-dynamic-libraries)
  - [Basic Tools: `nm`, `ldd`, `ldconfig`](#basic-tools-nm-ldd-ldconfig)
- [Tasks](#tasks)
  - [Task 0: A library is not a luxury but one of the necessities of life](#task-0-a-library-is-not-a-luxury-but-one-of-the-necessities-of-life)
  - [Task 1: Creating a Dynamic Library](#task-1-creating-a-dynamic-library)
  - [Task 2: Using a Dynamic Library](#task-2-using-a-dynamic-library)
  - [Task 3: Environment Variable Configuration](#task-3-environment-variable-configuration)
  - [Task 4: Comparing Dynamic and Static Libraries](#task-4-comparing-dynamic-and-static-libraries)
  - [Task 5: Exploring Library Tools](#task-5-exploring-library-tools)
- [Conclusion](#conclusion)

## General Concepts

### Dynamic Libraries

A dynamic library, also known as a shared library, is a collection of pre-compiled functions and code that can be used by multiple programs. Unlike static libraries, which are linked with the program at compile-time, dynamic libraries are loaded into memory at runtime.

Dynamic libraries provide several advantages:

- **Code Reusability**: Dynamic libraries allow multiple programs to use the same set of functions without duplicating code.
- **Memory Efficiency**: Dynamic libraries are loaded into memory only when needed, reducing the memory footprint of the programs.
- **Flexibility**: Dynamic libraries can be updated independently of the programs that use them. Changes to the library can be applied without recompiling the programs.

To create a dynamic library in C, we compile the source files into object files and then use a linker to create the shared library. The resulting dynamic library file has a `.so` extension on Linux systems.

### Environment Variable `$LD_LIBRARY_PATH`

The environment variable `$LD_LIBRARY_PATH` is used to specify the search path for dynamic libraries. When a program is executed, the system searches for the required dynamic libraries in the directories specified by `$LD_LIBRARY_PATH`. If a library is found, it is loaded into memory and linked with the program.

To use a dynamic library located in a custom directory, we can set the `$LD_LIBRARY_PATH` variable to include the path to that directory. This allows the program to find and load the library at runtime.

### Static Libraries vs. Dynamic Libraries

Static libraries and dynamic libraries serve the same purpose of code reuse, but they differ in how they are linked with the program:

- **Static Libraries**: Static libraries are linked with the program at compile-time. The object code from the static library is copied and merged into the final executable. The resulting binary file contains all the code needed to run the program, including the library functions. Static libraries have the advantage of simplicity and portability but can lead to larger executable sizes.
- \*\*Dynamic Libraries

\*\*: Dynamic libraries are linked with the program at runtime. The program contains references to the library functions but does not include their actual code. The dynamic library is loaded into memory and linked with the program during execution. This allows for smaller executable sizes and easier library updates.

### Basic Tools: `nm`, `ldd`, `ldconfig`

To work with dynamic libraries, several tools are available:

- **`nm`**: The `nm` command lists the symbols (functions and variables) defined in an object file or library. It helps to identify the functions available in a dynamic library and their names.
- **`ldd`**: The `ldd` command lists the dynamic dependencies of a program or shared library. It shows which dynamic libraries are required by a given binary and whether they are found or missing.
- **`ldconfig`**: The `ldconfig` command is used to configure dynamic linker run-time bindings. It maintains a cache of the shared libraries found in the directories specified by `$LD_LIBRARY_PATH` and other system default locations.

## Tasks

The project consists of several tasks, each focusing on a specific aspect of dynamic libraries and their usage. Here is a brief overview of the tasks:

### Task 0: A library is not a luxury but one of the necessities of life

In this task, we explore the basics of dynamic libraries by answering some questions related to their purpose, advantages, and usage scenarios. It helps establish a foundation for further understanding.

### Task 1: Creating a Dynamic Library

Task 1 involves creating a dynamic library called `libdynamic.so`. We compile two C source files into object files, and then we link them together to create the shared library. The resulting library can be used by other programs.

### Task 2: Using a Dynamic Library

In Task 2, we create a program that uses the dynamic library created in Task 1. We demonstrate how to link the program with the shared library during compilation and how to execute the program successfully.

### Task 3: Environment Variable Configuration

Task 3 focuses on configuring the `$LD_LIBRARY_PATH` environment variable. We explain how to set the variable to include the directory containing the dynamic library. This ensures the program can find and load the library at runtime.

### Task 4: Comparing Dynamic and Static Libraries

In this task, we compare dynamic and static libraries by creating a static library called `libstatic.a`. We explore the differences between the two types of libraries, including their file sizes, linking methods, and implications for program development and deployment.

### Task 5: Exploring Library Tools

Task 5 introduces some basic library tools: `nm`, `ldd`, and `ldconfig`. We demonstrate how these tools can be used to inspect dynamic libraries, identify missing dependencies, and manage the library cache.

## Conclusion

This repository provides an introduction to dynamic libraries in C, covering their purpose, creation, usage, and related concepts. By completing the tasks, you will gain hands-on experience working with dynamic libraries and understand their benefits in software development. Feel free to explore each task's instructions and code examples to deepen your understanding of this important topic.

For any questions or issues, please don't hesitate to reach out to [Alexander Udeogaranya](https://github.com/Dr-dyrane). Happy coding!
