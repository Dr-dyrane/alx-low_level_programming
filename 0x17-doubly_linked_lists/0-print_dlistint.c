#include "lists.h"

/**
 *print_dlistint - Prints all the elements of a dlistint_t list.
 *@h: Pointer to the head of the list
 *
 *Return: Number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;
	const dlistint_t *current;

	if (!h)
		return (count);

	for (current = h; current->prev; current = current->prev)
	{
		;
	}
	for (; current; current = current->next)
	{
		printf("%d\n", current->n);
		count++;
	}

	return (count);
}
