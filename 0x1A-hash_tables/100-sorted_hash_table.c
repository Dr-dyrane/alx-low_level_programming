#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the hash table array
 *
 * Return: Pointer to the created sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = NULL;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t) * size);
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * create_shash_node - creates a node for the sorted hash table
 * @key: key for the data
 * @value: data to be stored
 *
 * Return: pointer to the new node, or NULL on failure
 */
shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *new_node;

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
		return (NULL);

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = new_node->snext = new_node->sprev = NULL;

	return (new_node);
}

/**
 * add_to_sorted_list - add a node to the sorted (by key's ASCII) linked list
 * @table: the sorted hash table
 * @node: the node to add
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *temp;

	if (!table->shead && !table->stail)
	{
		table->shead = table->stail = node;
		return;
	}

	temp = table->shead;

	while (temp)
	{
		if (strcmp(node->key, tmp->key) < 0)
		{
			node->snext = temp;
			node->sprev = temp->sprev;
			temp->sprev = node;
			if (node->sprev)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		temp = temp->snext;
	}

	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - sets a key to a value in the hash table
 * @ht: sorted hash table
 * @key: key to the data
 * @value: data to add
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *new_value;
	shash_node_t *hn, *temp;

	if (!ht || !ht->array || ht->size == 0 ||
	    !key || strlen(key) == 0 || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	/* Update existing node if key already exists */
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			new_value = strdup(value);

			if (!new_value)
				return (0);

			free(temp->value);
			tmp->value = new_value;
			return (1);
		}
		temp = temp->next;
	}

	/* Create a new node */
	hn = create_shash_node(key, value);
	if (!hn)
		return (0);

	hn->next = ht->array[index];
	ht->array[index] = hn;
	add_to_sorted_list(ht, hn);

	return (1);
}

/**
 * shash_table_get - Gtes the value linked with a key in a sorted hash table
 * @ht: The sorted hash table
 * @key: The key to search for
 *
 * Return: The value associated with the key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (!ht || !ht->array || ht->size == 0 ||
	    !key || strlen(key) == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	npde = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table in ascending order
 * @ht: The sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (!ht || !ht->array)
		return;

	printf("{");
	node = ht->shead;
	while (node)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		first = 0;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in descending order
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (!ht || !ht->array)
		return;

	printf("{");
	node = ht->stail;
	while (node)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		first = 0;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp;
	unsigned long int i;

	if (!ht || !ht->array || ht->size == 0)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			temp = node;
			node = node->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}

	free(ht->array);
	free(ht);
}
