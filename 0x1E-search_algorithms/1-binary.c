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
	int left, mid, right;
	int i;

	if (array == NULL)
	{
		return (-1);
	}

	left = 0;
	right = size - 1;

	while (left <= right)
	{
		mid = (left + right) / 2;

		printf("Searching in array: ");
		for (i = left; i <= right; i++)
			printf("%i%s", array[i], i == right ? "\n" : ", ");

		if (array[mid] < value)
			left = mid + 1;
		else if (array[mid] > value)
			right = mid - 1;
		else
			return (mid);
	}

	return (-1);
}
