#include "sort.h"

/**
 * sift_down - Helper that ensures the subtree rooted at start is a max‐heap
 * @array: The array to adjust
 * @start: Index of the root of the subtree
 * @end:   Index of the last element in the heap
 * @size:  Total size of the array (for printing)
 */
static void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;

    while (root * 2 + 1 <= end)
    {
        size_t child = root * 2 + 1;
        size_t swap_idx = root;

        if (array[swap_idx] < array[child])
            swap_idx = child;
        if (child + 1 <= end && array[swap_idx] < array[child + 1])
            swap_idx = child + 1;

        if (swap_idx == root)
            return;

        /* swap root and child */
        {
            int tmp = array[root];
            array[root] = array[swap_idx];
            array[swap_idx] = tmp;
        }
        print_array(array, size);
        root = swap_idx;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *               using the sift‐down Heap sort algorithm.
 * @array: The array to sort
 * @size:  Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    /* 1) Build the max-heap */
    for (size_t i = (size - 2) / 2 + 1; i > 0; i--)
        sift_down(array, i - 1, size - 1, size);

    /* 2) Extract elements from heap one by one */
    for (size_t end = size - 1; end > 0; end--)
    {
        /* swap max (array[0]) with array[end] */
        {
            int tmp = array[0];
            array[0] = array[end];
            array[end] = tmp;
        }
        print_array(array, size);
        /* restore heap property on the reduced heap */
        sift_down(array, 0, end - 1, size);
    }
}
