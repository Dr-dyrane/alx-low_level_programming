# Hash Tables in C

This project focuses on implementing hash tables in the C programming language. Hash tables are data structures that provide efficient lookup, insertion, and deletion operations.

## Learning Objectives

By completing this project, you will gain knowledge and understanding of the following concepts:

- What is a hash function and what makes a good hash function?
- How do hash tables work and how to use them?
- Dealing with collisions in the context of a hash table.
- Advantages and drawbacks of using hash tables.
- Common use cases of hash tables.

## Project Files

The project consists of the following files:

- `0-hash_table_create.c`: Implementation of the `hash_table_create` function to create a new hash table.
- `1-djb2.c`: Implementation of the `djb2` hash function.
- `100-sorted_hash_table.c`: Implementation of a sorted hash table.
- `2-key_index.c`: Implementation of the `key_index` function to compute the index in the hash table array.
- `3-hash_table_set.c`: Implementation of the `hash_table_set` function to insert or update key-value pairs.
- `4-hash_table_get.c`: Implementation of the `hash_table_get` function to retrieve values from the hash table.
- `5-hash_table_print.c`: Implementation of the `hash_table_print` function to print the contents of the hash table.
- `6-hash_table_delete.c`: Implementation of the `hash_table_delete` function to free the memory allocated for the hash table.
- `hash_tables.h`: Header file containing data structure definitions and function prototypes.

## Requirements

- The code is written in C programming language.
- Compilation is done using gcc with the following flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- The code follows the Betty style guidelines.
- No global variables are used.
- Each file contains no more than 5 functions.
- The C standard library is allowed.
- A README.md file is present to provide project information.

## How to Use

To use the hash table functions in your own C program, follow these steps:

1. Copy the `hash_tables.h` header file to your project directory.
2. Include the `hash_tables.h` header in your C file: `#include "hash_tables.h"`.
3. Compile your C program with the hash table implementation files:
   ```
   gcc your_program.c 0-hash_table_create.c 1-djb2.c 100-sorted_hash_table.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c 6-hash_table_delete.c -o your_program
   ```
4. Run your program: `./your_program`.

## Resources

Here are some additional resources to learn more about hash tables:

- [What is a HashTable Data Structure - Introduction to Hash Tables, Part 0](https://www.youtube.com/watch?v=MfhjkfocRR0)
- [Hash Function](https://en.wikipedia.org/wiki/Hash_function)
- [Hash Table](https://en.wikipedia.org/wiki/Hash_table)
- [All about hash tables](https://www.cse.yorku.ca/~oz/hash.html)
- [Why hash tables and not arrays](https://www.youtube.com/watch?v=KyUTuwz_b7Q)

## Credits

This project is created and maintained by [Alexander Udeogaranya](https://github.com/Dr-dyrane) as part of the ALX Software Engineering program.
