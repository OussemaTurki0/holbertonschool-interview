#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"
#define MAX_SIZE   32

/**
 * display_array - Prints an array of integers, followed by a newline
 * @arr: Pointer to the array of integers
 * @len: Number of elements in the array
 */
static void display_array(int const *arr, size_t len)
{
    size_t idx;
    
    printf("Array: ");
    for (idx = 0; idx < len; idx++)
        printf("%s%d", idx ? ", " : "", arr[idx]);
    printf("\n");
}

/**
 * main - Program entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
    int array[MAX_SIZE];
    int move_direction;
    size_t index, length;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <L/R> <num1> [num2...]\n", argv[0]);
        return (EXIT_FAILURE);
    }

    /* Convert input arguments to an integer array */
    length = argc - 2;
    if (length > MAX_SIZE)
        length = MAX_SIZE;
    for (index = 0; index < length; index++)
        array[index] = atoi(argv[index + 2]);

    /* Show initial array */
    display_array(array, length);

    /* Determine direction */
    if (argv[1][0] == 'L')
    {
        move_direction = SLIDE_LEFT;
        printf("Shifting left...\n");
    }
    else if (argv[1][0] == 'R')
    {
        move_direction = SLIDE_RIGHT;
        printf("Shifting right...\n");
    }
    else
    {
        fprintf(stderr, "Invalid direction '%c'. Use 'L' or 'R'.\n", argv[1][0]);
        return (EXIT_FAILURE);
    }

    /* Execute slide and merge */
    if (!slide_line(array, length, move_direction))
    {
        fprintf(stderr, "Error: Unable to process slide and merge operation.\n");
        return (EXIT_FAILURE);
    }

    /* Show final array */
    display_array(array, length);
    
    return (EXIT_SUCCESS);
}
