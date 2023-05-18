#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Generate a key depending on a username for crackme5.
 * @argc: Number of arguments passed.
 * @argv: Arguments passed to main.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	unsigned int i, max_char;
	size_t len, sum;
	char *lookup;
	char key[7] = "      ";

	lookup = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	len = strlen(argv[1]);
	key[0] = lookup[(len ^ 59) & 63];
	sum = 0;
	for (i = 0; i < len; i++)
		sum += argv[1][i];
	key[1] = lookup[(sum ^ 79) & 63];
	max_char = 1;
	for (i = 0; i < len; i++)
		max_char *= argv[1][i];
	key[2] = lookup[(max_char ^ 85) & 63];
	max_char = argv[1][0];
	for (i = 0; i < len; i++)
	{
		if ((char)max_char <= argv[1][i])
			max_char = argv[1][i];
	}
	srand(max_char ^ 14);
	key[3] = lookup[rand() & 63];
	sum = 0;
	for (i = 0; i < len; i++)
		sum += argv[1][i] * argv[1][i];
	key[4] = lookup[(sum ^ 239) & 63];
	max_char = 0;
	for (i = 0; (char)i < argv[1][0]; i++)
		max_char = rand();
	key[5] = lookup[(max_char ^ 229) & 63];
	printf("%s\n", key);
	return (0);
}
