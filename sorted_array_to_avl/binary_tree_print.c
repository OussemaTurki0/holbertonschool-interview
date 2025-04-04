#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_tree - Prints a binary tree in 2D
 *
 * @tree: Pointer to the root node
 * @level: Current depth
 * @spaces: Whitespace for formatting
 */
static void print_tree(const binary_tree_t *tree, int level, int spaces)
{
    if (!tree)
        return;

    print_tree(tree->right, level + 1, spaces);

    for (int i = 0; i < level * spaces; i++)
        printf(" ");
    printf("(%03d)\n", tree->n);

    print_tree(tree->left, level + 1, spaces);
}

/**
 * binary_tree_print - Public function to print the binary tree
 * @tree: Pointer to the root node
 */
void binary_tree_print(const binary_tree_t *tree)
{
    print_tree(tree, 0, 6);
}
