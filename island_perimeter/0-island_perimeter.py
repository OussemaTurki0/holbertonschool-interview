#!/usr/bin/python3
"""
Module for calculating island perimeter
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in the grid.

    Args:
        grid (list of list of int): 2D grid of 0s (water) and 1s (land)

    Returns:
        int: perimeter of the island
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4

                # Check for land on the top
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2

                # Check for land on the left
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter
