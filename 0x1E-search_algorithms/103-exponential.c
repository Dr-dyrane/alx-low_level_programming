#include "search_algos.h"

int bsh(int *array, int value,
			 size_t low, size_t high);
size_t minimum(size_t a, size_t b);

/**
 * minimum - returns the minimum of two size_t values
 * @first: first value
 * @second: second value
 *
 * Return: `first` if lower or equal to `second`, `second` otherwise
 */
size_t minimum(size_t first, size_t second)
{
	return (first <= second ? first : second);
}

/**
 * bsh - searches for a value in an integer array using a
 * binary search algorithm, not guaranteed to return lowest index if `value`
 * appears twice in `array` (modified from `binary_search`)
 * @array: pointer to first element of array to seach
 * @value: The value to search for
 * @low: The low index of the search range
 * @high: The high index of the search range
 *
 * Return: index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int bsh(int *array, int value,
			 size_t low, size_t high)
{
	size_t mid, i;

	if (!array)
		return (-1);

	while (low <= high)
	{
		mid = (low + high) / 2;
		printf("Searching in array: ");
		for (i = low; i <= high; i++)
			printf("%i%s", array[i], i == high ? "\n" : ", ");
		if (array[mid] < value)
			low = mid + 1;
		else if (array[mid] > value)
			high = mid - 1;
		else
			return ((int)mid);
	}

	return (-1);
}

/**
 * exponential_search - searches for a value in a sorted array of integers
 * using an exponential search algorithm
 * @array: pointer to first element of array to search
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t low, high, bound = 1;

	if (!array || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = minimum(bound, size - 1);

	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	return (bsh(array, value, low, high));
}
