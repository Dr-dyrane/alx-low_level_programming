#include "search_algos.h"
#include <stdio.h>

/**
 * exponential_search - searches for a value in a sorted array of integers
 *                    using the Exponential search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where 'value' is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;	/* Initialize the exponential bound */
	size_t low;	/* Initialize the low index */
	size_t high;	/* Initialize the high index */
	int result;	/* Initialize the result of binary search */

	if (!array || size == 0)
		return (-1); /* Handle edge cases: NULL array or empty array */

	/* Find the exponential range that contains the value */
	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] =[%d]\n", bound, array[bound]);
		bound *= 2;	/* Double the bound */
	}

	/* Set the search range for binary search */
	low = bound / 2; /*The lower bound is the previous bound divided by 2 */
    /* The upper bound is the minimum of the current bound and the array size */
	high = (bound < size) ? bound : size - 1;

	printf("Value found between indexes[%lu] and[%lu]\n", low, high);

	/* Perform binary search within the range */
	result = binary_search(array, low, high, value);

	return (result);
}

/**
 * binary_search - searches for a value in a sorted array of integers
 *                using the Binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @low: The low index of the search range
 * @high: The high index of the search range
 * @value: The value to search for
 *
 * Return: The index where 'value' is located, or -1 if not found
 */
int binary_search(int *array, size_t low, size_t high, int value)
{
	size_t mid;	/* Initialize the middle index */

	while (low <= high)
	{
		mid = (low + high) / 2;	/* Calculate the middle index */

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
			return mid; /* Value found at the middle index */

		if (array[mid] < value)
			low = mid + 1; /* Adjust the search range to the right */
		else
			high = mid - 1; /* Adjust the search range to the left */
	}

	return (-1); /* Value not found in the subarray */
}