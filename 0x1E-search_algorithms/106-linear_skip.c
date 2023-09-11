#include "search_algos.h"
#include <math.h>
#include <stdio.h>

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: Pointer to the first node where 'value' is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (!list)
		return (NULL); /* Handle the case of NULL list */

	skiplist_t *express = list->express;
	skiplist_t *current = list;

	/* Traverse the express lane */
	while (express)
	{
		printf("Value checked at index[%lu] =[%d]\n", express->index, express->n);

		/**
         * If express node value is greater than or equal to the target value,
         * or express lane reaches the end, perform linear search in this range
         */
		if (express->n >= value || !express->express)
		{
			printf("Value found between indexes[%lu] and[%lu]\n",
				current->index, express->index);

			/* Linear search in the current range */
			while (current)
			{
				printf("Value checked at index[%lu] =[%d]\n", current->index, current->n);
				if (current->n == value)
					return (current);

				if (current->n > value)
					return (NULL);

				current = current->next;
			}

			break;
		}

		current = express;
		express = express->express;
	}

	return (NULL);
}
