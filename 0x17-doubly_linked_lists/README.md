# Doubly Linked Lists

This project implements a doubly linked list data structure in the C programming language. The doubly linked list is a type of linked list in which each node contains a data element, a reference to the next node, and a reference to the previous node. This allows for efficient traversal in both directions.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Functions](#functions)

## Introduction

A doubly linked list is a data structure that consists of a sequence of nodes. Each node contains a data element and two pointers, one pointing to the previous node and another pointing to the next node. This structure provides flexibility in traversing the list in both forward and backward directions.

This project provides a C implementation of doubly linked lists and includes functions for various operations such as insertion, deletion, searching, and printing the list. It serves as a foundation for understanding and working with doubly linked lists in C.

## Usage

To use the doubly linked list implementation in your C project, follow these steps:

1. Clone this repository or download the source code files.

2. Include the `lists.h` header file in your C program.

3. Use the provided functions to perform operations on the doubly linked list. Examples of usage can be found in the `main.c` file.

4. Compile your program with the doubly linked list source code files.

5. Run the compiled executable to observe the output or behavior of the doubly linked list operations.

## Functions

The following functions are available in the doubly linked list implementation:

- `size_t print_dlistint(const dlistint_t *h)`: Prints all the elements of the doubly linked list.

- `size_t dlistint_len(const dlistint_t *h)`: Returns the number of elements in the doubly linked list.

- `dlistint_t *add_dnodeint(dlistint_t **head, const int n)`: Adds a new node with the given data at the beginning of the doubly linked list.

- `dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)`: Adds a new node with the given data at the end of the doubly linked list.

- `void free_dlistint(dlistint_t *head)`: Frees the memory allocated for the doubly linked list.

- `dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)`: Returns the node at the specified index in the doubly linked list.

- `int sum_dlistint(dlistint_t *head)`: Returns the sum of all the data elements in the doubly linked list.

- `dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)`: Inserts a new node with the given data at the specified index in the doubly linked list.

- `int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)`: Deletes the node at the specified index from the doubly linked list.

Please refer to the source code files for detailed function implementations and additional comments.

Remember to include the necessary header files and handle memory allocation appropriately when using these functions.

This project is part of the ALX programming school curriculum.
