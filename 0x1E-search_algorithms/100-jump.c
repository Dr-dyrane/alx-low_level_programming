#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_search - searches for a value in a sorted array of integers
 *              using the Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where 'value' is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);	/* Calculate the jump step size */
	size_t left = 0;
	size_t right = 0;

	if (!array || size == 0)
		return (-1);

	printf("Value checked array[%lu] =[%d]\n", left, array[left]);

	/* Perform the jump until the value is > the current array element */
	while (array[right] < value && right < size)
	{
		left = right;
		right += step;

		/* If right is within bounds, print the checked value */
		if (right < size)
			printf("Value checked array[%lu] =[%d]\n", right, array[right]);
		else
			printf("Value checked array[%lu] =[%d]\n",
					size - 1, array[size - 1]);
	}

	printf("Value found between indexes[%lu] and[%lu]\n", left, right);

	/* Set right to the last index if it exceeds the array size */
	right = (right >= size) ? size - 1 : right;

	/* Perform linear search within the jump range */
	while (left <= right)
	{
		printf("Value checked array[%lu] =[%d]\n", left, array[left]);

		/* If the value is found, return its index */
		if (array[left] == value)
			return (left);

		left++;
	}
	return (-1);	/* Value not found in the array */
}
