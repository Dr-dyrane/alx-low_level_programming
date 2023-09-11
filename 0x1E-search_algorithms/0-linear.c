#include "search_algos.h"
#include <stdio.h>

/**
 * linear_search - searches for a value in an array of integers
 *                 using the Linear search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where 'value' is located, or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;	/* Initialize index 'i' to 0 */

	/* Check for NULL array or empty array */
	if (!array || size == 0)
		return (-1);

	while (i < size)	/* Iterate through the array */
	{
        printf("Value checked array[%lu] =[%d]\n",
         i, array[i]);  /* Print the checked value */
		if (array[i] == value)	/* If value is found, return its index */
			return (i);
		i++;
	}

	return (-1);	/* Value not found in the array */
}
