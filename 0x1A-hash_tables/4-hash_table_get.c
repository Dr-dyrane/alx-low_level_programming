#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a key
 * @ht: The hash table to look into
 * @key: The key to search for
 *
 * Return: The value associated with the element, or NULL ift there is no key
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current_node;

	if (!ht || !key || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];

	/* Traverse the linked list at the computed index */
	while (current_node)
	{
		/* Check if the key matches the current node's key */
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value);

		current_node = current_node->next;
	}

	/* Key was not found in the hash table */
	return (NULL);
}
