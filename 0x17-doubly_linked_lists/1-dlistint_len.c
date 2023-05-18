#include "lists.h"

/**
 *dlistint_len - Returns the number of elements in a linked dlistint_t list.
 *@h: Pointer to the head of the list
 *
 *Return: Number of elements in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;
	const dlistint_t *current;

	if (!h)
		return (count);

	for (current = h; current->prev; current = current->prev)
	{;
	}

	for (; current; current = current->next)
	{
		count++;
	}

	return (count);
}
