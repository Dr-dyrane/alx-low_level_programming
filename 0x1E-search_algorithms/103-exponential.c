#include "search_algos.h"

int binary_search(int *array, int value, size_t low, size_t high);
size_t minimum(size_t first, size_t second);

/**
 * minimum - returns the minimum of two size_t values
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
 * binary_search - searches for a value in a sorted array of integers
 *                using the Binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @low: The low index of the search range
 * @high: The high index of the search range
 * @value: The value to search for
 *
 * Return: The index where 'value' is located, or -1 if not found
 */

int binary_search(int *array, int value, size_t low, size_t high)
{
	size_t mid, i;

	if (!array)
		return (-1);

	while (low <= high)
	{
		mid = (low + high) / 2;/* Calculate the middle index */

		/* Print the current subarray being searched */
		printf("Searching in array: ");
		for (i = low; i <= high; i++)
			printf("%i%s", array[i], i == high ? "\n" : ", ");

		if (array[mid] < value)
			low = mid + 1;/* Adjust the search range to the right */

		else if (array[mid] > value)
			high = mid - 1;/* Adjust the search range to the left */

		else
			return ((int)mid);/* Value found at the middle index */
	}

	return (-1);/* Value not found in the subarray */
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
	size_t low, high, bound = 1;/* Initialize indexes & exponential bound */
	int result;/* Initialize the result of binary search */

	if (!array || size == 0)
		return (-1);/* Handle edge cases: NULL array or empty array */

	/* Find the exponential range that contains the value */
	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;/* Double the bound */
	}

	/* Set the search range for binary search */
	low = bound / 2;/*The lower bound is the previous bound divided by 2 */
	/* The upper bound is the minimum of the current bound & the array size */
	high = minimum(bound, size - 1);

	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	/* Perform binary search within the range */
	result = binary_search(array, value, low, high);

	return (result);
}