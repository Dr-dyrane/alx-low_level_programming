#include "search_algos.h"

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
	size_t left = 0;
	size_t right = size - 1;
	size_t position;
	double factor;

	if (!array)
		return (-1);

	while ((array[right] != array[left]) &&
	       (value >= array[left]) && (value <= array[right]))
	{
		factor = (double)(right - left) / (array[right] - array[left]);
		position = left + ((factor) * (value - array[left]));
		printf("Value checked array[%lu] = [%d]\n", position, array[position]);
		if (array[position] < value)
			left = position + 1;
		else if (value < array[position])
			right = position - 1;
		else
			return (position);
	}
	if (value == array[left])
	{
		printf("Value checked array[%lu] = [%d]\n", left, array[left]);
		return (left);
	}
	position = left + (((double)(right - left) / (array[right] - array[left]))
		     * (value - array[left]));
	printf("Value checked array[%lu] is out of range\n", position);
	return (-1);
}
