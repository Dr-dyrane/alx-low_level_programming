#include "search_algos.h"
#include <stdio.h>

/**
 * interpolation_search - searches for a value in a sorted array of integers
 *                       using the Interpolation search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where 'value' is located, or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t l = 0; /* Initialize the low index to 0 */
	size_t h = size - 1; /* Initialize the high index to the last element */
	size_t p; /* Initialize the position variable */
	double interpolation_factor;

	if (!array || size == 0)
		return (-1); /* Handle edge cases: NULL array or empty array */

	while (l <= h && value >= array[l] && value <= array[h])
	{
		/* Calculate the probe position using Interpolation formula */
		interpolation_factor = (double)(h - l) / (array[h] - array[l]);
		p = l + (interpolation_factor * (value - array[l]));

		/* Print the probed value */
		printf("Value checked array[%lu] =[%d]\n", p, array[p]);

		if (array[p] == value)
			return (p); /* Value found at the probe position */

		if (array[p] < value)
			l = p + 1; /* Adjust the search range to the right */
		else
			h = p - 1; /* Adjust the search range to the left */
	}
	/* Value not found in the array */
	printf("Value checked array[%lu] is out of range\n", p);
	return (-1);
}

