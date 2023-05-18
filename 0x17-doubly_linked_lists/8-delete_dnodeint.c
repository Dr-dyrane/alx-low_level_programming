#include "lists.h"

/**
 *delete_dnodeint_at_index - Deletes the node at a given position in a dl list.
 *@head: Pointer to a pointer to the head of the list.
 *@index: Index of the node to be deleted.
 *
 *Return: 1 if the deletion succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int i = 0;

	if (!head || !(*head))
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		if (current->next)
			current->next->prev = NULL;
		free(current);
		return (1);
	}

	while (current && i < index)
	{
		current = current->next;
		i++;
	}

	if (!current)
		return (-1);

	if (current->next)
		current->next->prev = current->prev;

	if (current->prev)
		current->prev->next = current->next;

	free(current);
	return (1);
}
