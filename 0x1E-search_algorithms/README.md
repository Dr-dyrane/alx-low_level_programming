# C - Search Algorithms

This project is a part of the ALX Software Engineering program and focuses on implementing various search algorithms in the C programming language. The main objective of this project is to familiarize you with different search algorithms, their time and space complexities, and their practical applications.

### Overview

This project, "0x1E-search_algorithms," is a collection of various search algorithms implemented in the C programming language. These algorithms are essential tools in computer science and software development for efficiently searching for specific elements within data structures.

## Table of Contents

1. [Project Description](#project-description)
2. [Project Structure](#project-structure)
3. [Task Explanations](#task-explanations)
    - [Task 0: Linear Search](#task-0-linear-search)
    - [Task 1: Binary Search](#task-1-binary-search)
    - [Task 2: Big O Notation](#task-2-big-o-notation)
    - [Task 3: Space Complexity](#task-3-space-complexity)
    - [Task 4: Time Complexity of Binary Search](#task-4-time-complexity-of-binary-search)
    - [Task 5: Space Complexity of Binary Search](#task-5-space-complexity-of-binary-search)
    - [Task 6: Space Complexity of allocate_map](#task-6-space-complexity-of-allocate_map)
    - [Task 7: Jump Search](#task-7-jump-search)
    - [Task 8: Time Complexity of Jump Search](#task-8-time-complexity-of-jump-search)
    - [Task 9: Interpolation Search](#task-9-interpolation-search)
    - [Task 10: Exponential Search](#task-10-exponential-search)
    - [Task 11: Advanced Binary Search](#task-11-advanced-binary-search)
    - [Task 12: Jump Search in a Singly Linked List](#task-12-jump-search-in-a-singly-linked-list)
    - [Task 13: Linear Search in a Skip List](#task-13-linear-search-in-a-skip-list)
4. [List of Algorithms](#list-of-algorithms)
5. [Getting Started](#getting-started)
6. [Usage](#usage)
7. [Contributing](#contributing)
8. [License](#license)
8. [Author](#author)

## Project Description

In this project, you will implement several search algorithms and analyze their time and space complexities. You will work with various types of data structures, including arrays and linked lists, to search for a specific value efficiently.

## Project Structure

The project contains the following files and directories:

- `0-linear.c`: Implementation of the linear search algorithm.
- `1-binary.c`: Implementation of the binary search algorithm.
- `2-O`: Text file containing the time complexity of linear search.
- `3-O`: Text file containing the space complexity of iterative linear search.
- `4-O`: Text file containing the time complexity of binary search.
- `5-O`: Text file containing the space complexity of binary search.
- `6-O`: Text file containing the space complexity of the `allocate_map` function.
- `100-jump.c`: Implementation of the jump search algorithm.
- `101-O`: Text file containing the average case time complexity of jump search.
- `102-interpolation.c`: Implementation of the interpolation search algorithm.
- `103-exponential.c`: Implementation of the exponential search algorithm.
- `104-advanced_binary.c`: Implementation of an advanced binary search algorithm.
- `105-jump_list.c`: Implementation of jump search in a singly linked list.
- `106-linear_skip.c`: Implementation of linear search in a skip list.
- `search_algos.h`: Header file containing function prototypes and data structures.

## Task Explanations

- Implement a function that searches for a value in an array of integers using the Linear search algorithm.
- Prototype: `int linear_search(int *array, size_t size, int value);`
- The function should return the first index where the `value` is located.
- If `value` is not present in the array or if `array` is `NULL`, the function should return `-1`.
- During the search, print the values being compared.

### Task 1: Binary Search

- Implement a function that searches for a value in a sorted array of integers using the Binary search algorithm.
- Prototype: `int binary_search(int *array, size_t size, int value);`
- The function should return the index where `value` is located.
- You can assume that the `array` will be sorted in ascending order.
- You can assume that `value` won't appear more than once in the array.
- If `value` is not present in the array or if `array` is `NULL`, the function should return `-1`.
- Print the array being searched every time it changes during the search.

### Task 2: Big O Notation

- Answer the question: What is the time complexity (worst case) of a linear search in an array of size `n`?
- Provide the answer in the format of Big O notation.

It appears that you have provided a set of programming tasks related to search algorithms in the C programming language. Each task has specific requirements and examples. To help you get started with these tasks, I'll provide you with some guidance and explanations for each task.

### Task 0: Linear Search
In this task, you need to implement a linear search algorithm to find a given value in an array of integers. Here are the key points:

- Prototype: `int linear_search(int *array, size_t size, int value);`
- You must return the first index where `value` is located.
- If `value` is not present in the array or if `array` is NULL, your function must return -1.
- You should print the value you are comparing every time you compare a value in the array to the target value.

### Task 1: Binary Search
In this task, you need to implement a binary search algorithm to find a given value in a sorted array of integers. Here are the key points:

- Prototype: `int binary_search(int *array, size_t size, int value);`
- You must return the index where `value` is located.
- You can assume that the `array` will be sorted in ascending order.
- You can assume that `value` won't appear more than once in the array.
- If `value` is not present in the array or if `array` is NULL, your function must return -1.
- You should print the array being searched every time it changes.

### Tasks 2 to 5: Big O Notation
In these tasks, you are asked to determine the time and space complexities (worst case) of various search algorithms, such as linear search, binary search, and others. You need to provide the Big O notation for these complexities.

### Task 6: Space Complexity
Here, you need to determine the space complexity of a given function/algorithm. The provided function allocates memory for a two-dimensional array using `malloc`. Calculate and provide the space complexity.

### Task 7: Jump Search
In this advanced task, you are required to implement the Jump search algorithm to find a given value in a sorted array of integers. Key points:

- Prototype: `int jump_search(int *array, size_t size, int value);`
- You need to use the square root of the size of the array as the jump step.
- You should use the `sqrt()` function from the `<math.h>` library (compile with `-lm`).
- You should print the value you are comparing every time you compare a value in the array to the target value.

### Task 8: Time Complexity of Jump Search
In this task, you need to determine the average case time complexity of the Jump search algorithm when using a step size of sqrt(n).

### Task 9: Interpolation Search
Here, you need to implement the Interpolation search algorithm to find a given value in a sorted array of integers. Key points:

- Prototype: `int interpolation_search(int *array, size_t size, int value);`
- You should use a formula to determine the probe position.
- You should print the value you are comparing every time you compare a value in the array to the target value.

### Task 10: Exponential Search
This task requires you to implement the Exponential search algorithm to find a given value in a sorted array of integers. Key points:

- Prototype: `int exponential_search(int *array, size_t size, int value);`
- You need to use powers of 2 as exponential ranges to search in your array.
- You should print the value you are comparing every time you compare a value in the array to the target value.
- Once you've found the range, use a binary search.

### Task 11: Advanced Binary Search
In this advanced task, you need to implement a modified binary search that returns the index of the first occurrence of a value in a sorted array. You must use recursion for this task.

### Task 12: Jump Search in a Singly Linked List
Here, you need to implement the Jump search algorithm for a sorted singly linked list. Key points:

- Prototype: `listint_t *jump_list(listint_t *list, size_t size, int value);`
- Use an "express lane" by placing nodes at multiples of the square root of the list size.
- Print the value you are comparing for each comparison.
- Return a pointer to the first node where `value` is located.

### Task 13: Linear Search in a Skip List
In this advanced task, you need to implement linear search in a sorted skip list of integers. Key points:

- Prototype: `skiplist_t *linear_skip(skiplist_t *list, int value);`
- The skip list has an "express lane" with nodes at multiples of the square root of the list size.
- Print the value you are comparing for each comparison.
- Return a pointer to the first node where

 `value` is located.
Creating a comprehensive README for a GitHub project is an important step in making your project accessible and understandable to others. Below, I've prepared a detailed README for the project authored by Alexander Udeogaranya, titled "0x1E-search_algorithms."

### Project Description

This repository contains C programs that demonstrate the implementation of various search algorithms. Each algorithm is contained within its own source file and is thoroughly documented to help users understand the underlying logic and usage. The primary goal of this project is to provide a resource for learning and understanding different search algorithms and their applications.

### List of Algorithms

The following search algorithms are implemented in this project:

1. **Linear Search (linear_search.c)**: This is a simple search algorithm that iterates through the given array to find the target element.

2. **Binary Search (binary_search.c)**: A more efficient algorithm for searching in sorted arrays. It repeatedly divides the search interval in half until the target element is found or determined to be absent.

3. **Jump Search (jump_search.c)**: This algorithm jumps ahead by fixed steps to find a range where the target element is likely to be and then performs a linear search within that range.

4. **Interpolation Search (interpolation_search.c)**: A variation of binary search that works well for uniformly distributed data. It estimates the position of the target element within the array.

### Getting Started

To get started with this project, follow these steps:

1. **Clone the Repository**: Use the following command to clone this repository to your local machine:

   ```bash
   git clone https://github.com/Dr-dyrane/alx-low_level_programming/0x1E-search_algorithms
   ```

2. **Compile the Programs**: Navigate to the project directory and compile the C programs using your preferred C compiler. For example:

   ```bash
   gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c 0-linear.c -o 0-linear
   ```

### Usage

Once you have compiled the programs, you can run them individually to see the search algorithms in action. Each C file contains a specific algorithm that can be executed independently. For example:

```bash
./0-linear.c
./1-binary.c
./100-jump.c
./102-interpolation.c
```

Feel free to modify the input data or target values in the source code to test different scenarios.

### Contributing

Contributions to this project are welcome. If you'd like to contribute improvements, additional search algorithms, or bug fixes, please follow these steps:

1. Fork the repository to your GitHub account.
2. Create a new branch for your contributions.
3. Make your changes and ensure that the code passes any existing tests.
4. Create a pull request to submit your changes for review.

### License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author: [Alexander Udeogaranya](https://github.com/Dr-dyrane/alx-low_level_programming/0x1E-search_algorithms)