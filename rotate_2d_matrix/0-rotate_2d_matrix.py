#!/usr/bin/python3
"""
Rotate a 2D matrix 90 degrees clockwise in-place
"""


def rotate_2d_matrix(matrix):
    """
    Rotates an n x n matrix 90 degrees clockwise in-place.
    Args:
        matrix (list of list of int): 2D matrix to rotate
    """
    n = len(matrix)

    # Transpose the matrix (swap rows and columns)
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse each row
    for i in range(n):
        matrix[i].reverse()
