#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: Pointer to the first node where 'value' is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *stop = NULL;

	if (!list)
		return (NULL); /* Handle the case of NULL list */

	/* Traverse the express lane */
	while (current && current->express && current->express->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       current->express->index, current->express->n);
		current = current->express;
	}
	stop = current;

	for (; stop && stop->next != stop->express; stop = stop->next)

	if (current->express)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       current->express->index, current->express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		       current->index, current->express->index);
	}
	else
		printf("Value found between indexes [%lu] and [%lu]\n",
		       current->index, stop->index);

	for (; current != stop && current->n < value; current = current->next)
		printf("Value checked at index [%lu] = [%i]\n",
		       current->index, current->n);
	printf("Value checked at index [%lu] = [%i]\n",
	       current->index, current->n);

	if (current == stop)
		return (NULL);

	return (current);
}
