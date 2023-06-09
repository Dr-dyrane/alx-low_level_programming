#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the hash table
 *
 * Return: pointer to the new table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht;
	unsigned long int ai = 0;

	sht = malloc(sizeof(shash_table_t));
	if (!sht)
		return (NULL);

	sht->size = size;
	sht->shead = NULL;
	sht->stail = NULL;

	sht->array = malloc(sizeof(shash_node_t) * size);
	if (!sht->array)
	{
		free(sht);
		return (NULL);
	}
	while (ai < size)
	{
		sht->array[i] = NULL;
		ai++;
	}

	return (sht);
}

/**
 * make_shash_node - makes a node for the sorted hash table
 * @key: key for the data
 * @value: data to be stored
 *
 * Return: pointer to the new node, or NULL on failure
 */
shash_node_t *make_shash_node(const char *key, const char *value)
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
	shash_node_t *shn, *temp;

	if (!ht || !ht->array || ht->size == 0 ||
	    !key || strlen(key) == 0 || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	temp = ht->array[index];
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);

			free(temp->value);
			temp->value = new_value;

			return (1);
		}
		temp = temp->next;
	}

	shn = make_shash_node(key, value);
	if (shn == NULL)
		return (0);

	shn->next = ht->array[index];
	ht->array[index] = shn;

	add_to_sorted_list(ht, shn);

	return (1);
}

/**
 * shash_table_get - retrieve a value from the hash table
 * @ht: hash table
 * @key: key to the data
 *
 * Return: the value associated with key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *temp;

	if (!ht || !ht->array || ht->size == 0 ||
	    !key || strlen(key) == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	temp = ht->array[index];
	while (temp)
	{
		if (strcmp(tmp->key, key) == 0)
			return (temp->value);

		temp = temp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	char flag = 0;

	if (!ht || !ht->array)
		return;

	printf("{");

	temp = ht->shead;
	while (temp)
	{
		if (flag == 1)
			printf(", ");

		printf("'%s': '%s'", temp->key, temp->value);

		flag = 1;
		temp = temp->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	char flag = 0;

	if (!ht || !ht->array)
		return;

	printf("{");

	temp = ht->stail;
	while (temp)
	{
		if (flag == 1)
			printf(", ");

		printf("'%s': '%s'", temp->key, temp->value);

		flag = 1;
		temp = temp->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int ai = 0;
	shash_node_t *next;

	if (!ht || !ht->array || ht->size == 0)
		return;

	while (ai < ht->size)
	{
		while (ht->array[ai])
		{
			next = ht->array[ai]->next;
			free(ht->array[ai]->key);
			free(ht->array[ai]->value);
			free(ht->array[ai]);
			ht->array[ai] = next;
		}

		ai++;
	}

	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
