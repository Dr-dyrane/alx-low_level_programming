#include "search_algos.h"
#include <stdio.h>

/**
 * advanced_binary - searches for a value in a sorted array of integers
 *                  using an advanced binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where 'value' is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1); /*Handle edge cases: NULL array or empty array */

	return (advanced_binary_recursive(array, 0, size - 1, value));
}

/**
 * advanced_binary_recursive - performs recursive binary search
 * @array: Pointer to the first element of the array to search in
 * @low: The low index of the current search range
 * @high: The high index of the current search range
 * @value: The value to search for
 *
 * Return: The index where 'value' is located, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid; /* Initialize the middle index */

	if (low > high)
		return (-1); /* Value not found in the subarray */

	mid = low + (high - low) / 2; /* Calculate the middle index */

	/* Print the current subarray being searched */
	printf("Searching in array: ");
	for (size_t i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i < high)
			printf(", ");
	}

	printf("\n");

	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] != value)
		/* Value found at the middle index, the first occurrence */
			return mid;
		return (advanced_binary_recursive(array, low, mid, value));
	}
	else if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, high, value));
	else
		return (advanced_binary_recursive(array, low, mid - 1, value));
}
