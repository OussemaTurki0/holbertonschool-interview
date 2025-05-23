#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/* Prototypes for helper functions (not provided in task) */
heap_t *_array_to_heap(int *array, size_t size);
void binary_tree_print(const binary_tree_t *);

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
    heap_t *tree;
    int array[] = {79, 47, 68, 87, 84, 91, 21, 32, 34, 2, 20, 22, 98, 1, 62, 95};
    size_t n = sizeof(array) / sizeof(array[0]);
    int extract;

    tree = _array_to_heap(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);

    extract = heap_extract(&tree);
    printf("Extracted: %d\n", extract);
    binary_tree_print(tree);

    extract = heap_extract(&tree);
    printf("Extracted: %d\n", extract);
    binary_tree_print(tree);

    extract = heap_extract(&tree);
    printf("Extracted: %d\n", extract);
    binary_tree_print(tree);

    return (0);
}
