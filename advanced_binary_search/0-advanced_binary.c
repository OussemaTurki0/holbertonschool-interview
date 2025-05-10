#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints the elements in a given array
 * @array: Pointer to the first element of the array
 * @low: Starting index
 * @high: Ending index
 */
void print_array(int *array, int low, int high)
{
	int i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i < high)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_recursive - Recursively searches for first occurrence of value
 * @array: Pointer to array
 * @low: Starting index
 * @high: Ending index
 * @value: Value to search for
 * Return: Index of first occurrence, or -1
 */
int binary_recursive(int *array, int low, int high, int value)
{
	int mid;

	if (low > high)
		return (-1);

	print_array(array, low, high);
	mid = low + (high - low) / 2;

	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
			return (mid);
		return (binary_recursive(array, low, mid, value));
	}
	else if (array[mid] < value)
		return (binary_recursive(array, mid + 1, high, value));
	else
		return (binary_recursive(array, low, mid - 1, value));
}

/**
 * advanced_binary - Searches for first occurrence of value using recursion
 * @array: Pointer to sorted array
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: Index of first match or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);
	return (binary_recursive(array, 0, size - 1, value));
}
