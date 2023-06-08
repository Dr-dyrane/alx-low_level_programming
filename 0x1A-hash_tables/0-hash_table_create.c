#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table,
 *       or NULL if something went wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int ai;

	/* Allocate memory for the hash table */
	ht = malloc(sizeof(hash_table_t));
	if (!ht)
		return (NULL);

	/* Alloctae memory for the array */
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	/* Initialize each element of the array to NULL */
	for (ai = 0; ai < size; ai++)
		ht->array[ai] = NULL;

	ht->size = size;

	return (ht);
}
