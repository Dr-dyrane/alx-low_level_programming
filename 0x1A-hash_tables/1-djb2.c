#include "hash_tables.h"

/**
 * hash_djb2 - Implementation of the djb2 hash algorithm
 * @str: String used to generate the hash value
 *
 * Return: Hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *str++))
	{
		/* hash * 33 + c */
		hash = ((hash << 5) + hash) ^ c;
	}

	return (hash);
}
