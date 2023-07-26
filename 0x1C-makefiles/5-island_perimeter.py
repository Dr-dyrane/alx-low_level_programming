#!/usr/bin/python3
"""
5-island_perimeter.py

This script defines a function to calculate the perimeter of an island
represented by a grid of 0s and 1s.

Requirements:
- The grid represents water with 0 and land with 1.
- Each cell in the grid is a square with side length 1.
- Grid cells are connected horizontally/vertically (not diagonally).
- The grid is rectangular, with width and height not exceeding 100.
- The grid is completely surrounded by water, and there is only one island
  (or nothing).
- The island doesn’t have “lakes” (water inside that isn’t connected to the
  water around the island).

Functions:
- island_perimeter(grid): Calculates the perimeter of the island defined in
  the input grid.

Attributes:
    grid (list): A list of lists representing the island, with 0s and 1s.

Returns:
    The perimeter of the island defined in the grid.

Example:
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))  # Output: 12
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island represented by the input grid.

    Args:
        grid (list): A list of lists representing the island, with 0s and 1s.

    Returns:
        The perimeter of the island defined in the grid.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                size += 1
                if j > 0 and grid[i][j - 1] == 1:
                    edges += 1
                if i > 0 and grid[i - 1][j] == 1:
                    edges += 1

    return size * 4 - edges * 2
