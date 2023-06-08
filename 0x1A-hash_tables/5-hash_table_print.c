#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int first = 1;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			/* If it's not the first pair, print comma and space */
			if (!first)
				printf(", ");

			/* Print the key-value pair */
			printf("'%s': '%s'", node->key, node->value);

			first = 0; /* Set first to 0 after printing first pair */

			node = node->next;
		}
	}
	printf("}\n");
}
