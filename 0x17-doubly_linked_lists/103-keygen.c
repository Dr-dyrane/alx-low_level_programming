#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * xor_operation - Performs XOR operation between two numbers.
 * @a: First number.
 * @b: Second number.
 *
 * Return: XOR result.
 */
unsigned int xor_operation(unsigned int a, unsigned int b)
{
	return (a ^ b);
}

/**
 * calculate_sum - Calculates the sum of character codes in a string.
 * @str: Input string.
 *
 * Return: Sum of character codes.
 */
size_t calculate_sum(const char *str)
{
	size_t sum = 0;
	size_t len = strlen(str);
	unsigned int i;

	for (i = 0; i < len; i++)
	{
		sum += str[i];
	}

	return (sum);
}

/**
 * calculate_product - Calculates the product of character codes in a string.
 * @str: Input string.
 *
 * Return: Product of character codes.
 */
unsigned int calculate_product(const char *str)
{
	unsigned int product = 1;
	size_t len = strlen(str);
	unsigned int i;

	for (i = 0; i < len; i++)
	{
		product *= str[i];
	}

	return (product);
}

/**
 * generate_key - Generates a key based on the username.
 * @username: Input username.
 * @key: Output key.
 *
 * This function generates a key based on the given username by performing
 * various calculations and lookups.
 */
void generate_key(const char *username, char *key)
{
	unsigned int i;
	size_t len, add;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	len = strlen(username);

	/* Perform XOR operation and select character from lookup */
	key[0] = l[xor_operation(len, 59) & 63];

	/* Calculate sum of character codes and select character from lookup */
	add = calculate_sum(username);
	key[1] = l[xor_operation(add, 79) & 63];

	/* Calculate product of character codes and select character from lookup */
	key[2] = l[xor_operation(calculate_product(username), 85) & 63];

	/* Generate a random character from the lookup string */
	key[3] = l[rand() & 63];

	/* Calculate squared sum of character codes & select from lookup */
	key[4] = l[xor_operation(calculate_sum(username) * calculate_sum(username),
				239) & 63];

	/* Generate a random character from the lookup */
	key[5] = l[xor_operation(rand(), 229) & 63];
}

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	char key[7] = "      ";

	/* Check if the number of command-line arguments is correct */
	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	/* Generate the key based on the provided username */
	generate_key(argv[1], key);

	/* Print the generated key */
	printf("%s\n", key);

	return (0);
}
