#include "search_algos.h"
#include <math.h>
#include <stdio.h>

/**
 * jump_list - searches for a value in a sorted list of integers
 *            using the Jump search algorithm
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where 'value' is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	if (!list || size == 0)
		return (NULL); /* Handle edge cases: NULL list or empty list */

	size_t step = (size_t) sqrt(size); /* Calculate the jump step */
	listint_t *current = list; /* Initialize the current node */

	while (current->next && current->n < value)
	{
		printf("Value checked at index[%lu] =[%d]\n", current->index, current->n);
		current = current->next;

		/* If the next node is beyond the value, perform a linear search */
		if (current->n >= value || !current->next)
			break;

		/* Move forward by 'step' nodes */
		for (size_t i = 0; i < step; i++)
		{
			if (current->next)
				current = current->next;
			else
				break;
		}
	}

	printf("Value found between indexes[%lu] and[%lu]\n", current->index, current->index + step);

	/* Perform linear search within the jump step range */
	while (current->n < value && current->next)
	{
		printf("Value checked at index[%lu] =[%d]\n", current->index, current->n);
		current = current->next;
	}

	/* If the value is found, return the node; otherwise, return NULL */
	printf("Value checked at index[%lu] =[%d]\n", current->index, current->n);
	return (current->n == value ? current : NULL);
}