#include "search_algos.h"
#include <stdio.h>

/**
 * binary_search - searches for a value in a sorted array of integers
 *                using the Binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where 'value' is located, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	/* Initialize left and right pointers */
	size_t left = 0, right = size - 1;
	size_t mid;

	/* Check for NULL array or empty array */
	if (!array || size == 0)
		return (-1);

	/* Binary search loop */
	while (left <= right)
	{
		print_array(array, left, right);

		mid = (left + right) / 2; /*Calculate the middle index */

		/*Check if the middle element is the target value */
	if (array[mid] == value)
		return (mid);
	/*If the target value is greater, search the right half */
		else if (array[mid] < value)
			left = mid + 1;
		else /*If the target value is smaller, search the left half */
			right = mid - 1;
	}

	return (-1); /*Value not found in the array */
}

/**
 * print_array - prints the current subarray being searched
 * @array: Pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%i%s", array[i]);
		if (i < end)
			printf(", ");
		else
			printf("\n");
	}
}
