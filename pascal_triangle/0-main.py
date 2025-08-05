#!/usr/bin/python3
"""
0-main
Test file for pascal_triangle function
"""

pascal_triangle = __import__('0-pascal_triangle').pascal_triangle


def print_triangle(triangle):
    """
    Prints a Pascal's Triangle in list format
    """
    for row in triangle:
        print("[{}]".format(",".join([str(x) for x in row])))


if __name__ == "__main__":
    print("n = 0:")
    print_triangle(pascal_triangle(0))

    print("\nn = 1:")
    print_triangle(pascal_triangle(1))

    print("\nn = 5:")
    print_triangle(pascal_triangle(5))

    print("\nn = 10:")
    print_triangle(pascal_triangle(10))
