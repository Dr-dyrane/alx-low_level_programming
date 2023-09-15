#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted list of integers
 *            using the Jump search algorithm
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where 'value' is located, or NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = 0;
	size_t step_size = sqrt(size);/* Calculate the jump step */
	listint_t *c_node, *jump;

	if (list == NULL || size == 0)
		return (NULL);/* Handle edge cases: NULL list or empty list */

	for (c_node = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		c_node = jump;
		for (step += step_size; jump->index < step; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			c_node->index, jump->index);

	/* Perform linear search within the jump step range */
	while (c_node->index < jump->index && c_node->n < value)
	{
		printf("Value checked at index [%ld] = [%d]\n", c_node->index, c_node->n);
		c_node = c_node->next;
	}

	/* If the value is found, return the node; otherwise, return NULL */
	printf("Value checked at index [%ld] = [%d]\n", c_node->index, c_node->n);

	return (c_node->n == value ? c_node : NULL);
}