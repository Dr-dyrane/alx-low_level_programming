#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * get_key_character - Calculates a key character based on given parameters.
 * @value: Value to perform XOR operation on.
 * @bitmask: Bitmask to apply after XOR operation.
 *
 * Return: Key character.
 */
char get_key_character(unsigned int value, unsigned int bitmask)
{
	char *lookup = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	return (lookup[(value ^ bitmask) & 63]);
}

/**
 * main - generate a key depending on a username for crackme5
 * @argc: number of arguments passed
 * @argv: arguments passed to main
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int i, b;
	size_t len, add;
	char p[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	len = strlen(argv[1]);
	p[0] = get_key_character(len, 59);

	for (i = 0, add = 0; i < len; i++)
		add += argv[1][i];
	p[1] = get_key_character(add, 79);

	for (i = 0, b = 1; i < len; i++)
		b *= argv[1][i];
	p[2] = get_key_character(b, 85);

	for (b = argv[1][0], i = 0; i < len; i++)
	{
		if ((char)b <= argv[1][i])
			b = argv[1][i];
	}

	srand(b ^ 14);
	p[3] = get_key_character(rand(), 63);

	for (b = 0, i = 0; i < len; i++)
		b += argv[1][i] * argv[1][i];
	p[4] = get_key_character(b, 239);

	for (b = 0, i = 0; (char)i < argv[1][0]; i++)
		b = rand();
	p[5] = get_key_character(b, 229);

	printf("%s\n", p);
	return (0);
}
