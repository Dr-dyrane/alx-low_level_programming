#include "lists.h"

/**
 *sum_dlistint - Returns the sum of all the data in a double linked list.
 *@head: Pointer to the head of the list.
 *
 *Return: The sum of all the data, or 0 if the list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current = head;

	while (current)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
