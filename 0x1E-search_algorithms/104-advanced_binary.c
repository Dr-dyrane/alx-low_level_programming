#include "search_algos.h"

int advanced_binary_recursive(int *array, int value,
			    size_t low, size_t high);

/**
 * advanced_binary_recursive - performs recursive binary search
 * @array: Pointer to the first element of the array to search in
 * @value: value to search for
 * @low: starting index in array
 * @high: ending index in array
 *
 * Return: The index where 'value' is located, or -1 if not found
 */
int advanced_binary_recursive(int *array, int value,
			    size_t low, size_t high)
{
	size_t mid, i;

	if (!array)
		return (-1);

	mid = (low + high) / 2;/* Calculate the middle index */

	/* Print the current subarray being searched */
	printf("Searching in array: ");
	for (i = low; i <= high; i++)
		printf("%i%s", array[i], i == high ? "\n" : ", ");

	if (array[low] == value)
		return ((int)low);

	if (array[low] != array[high])
	{
		if (array[mid] < value)
			return (advanced_binary_recursive(array, value,
							mid + 1, high));
		if (array[mid] >= value)
			return (advanced_binary_recursive(array, value,
							low, mid));
	}

	return (-1);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 *                  using an advanced binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where 'value' is located, or -1 if not found
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;

	if (!array)
		return (-1);/*Handle edge cases: NULL array or empty array */

	return (advanced_binary_recursive(array, value, low, high));
}
