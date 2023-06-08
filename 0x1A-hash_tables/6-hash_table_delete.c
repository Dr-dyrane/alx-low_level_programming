#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node, *temp;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			temp = node;
			node = node->next;
			free(temp->key); /* Free the key */
			free(temp->value); /* Free the value */
			free(temp); /* Free the node */
		}
	}
	free(ht->array); /* Free the array */
	free(ht); /* Free the hash table */
}
