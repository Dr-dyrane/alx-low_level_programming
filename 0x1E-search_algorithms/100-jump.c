#include "search_algos.h"
#include <math.h>

/* remember compiling math.h with gcc requires `-lm` */

size_t minimum(size_t first, size_t second);

/**
 * minimun - returns the minimum of two size_t values
 * @first: first value
 * @second: second value
 *
 * Return: `a` if lower or equal to `b`, `b` otherwise
 */
size_t minimum(size_t first, size_t second)
{
	return (first <= second ? first : second);
}

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
	size_t left, right, step;

	if (!array || size == 0)
		return (-1);

	step = sqrt(size);/* Calculate the jump step size */

	/* Perform the jump until the value is > the current array element */
	for (right = 0; right < size && array[right] < value;
	     left = right, right += step)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       right, array[right]);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", left, right);

	/* Perform linear search within the jump range */
	for (; left <= minimum(right, size - 1); left++)
	{
		printf("Value checked array[%lu] = [%d]\n", left, array[left]);

		/* If the value is found, return its index */
		if (array[left] == value)
			return (left);
	}

	return (-1);/* Value not found in the array */
}
