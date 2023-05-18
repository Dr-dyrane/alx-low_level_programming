#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LOOKUP "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"

/**
 *main - Generate a key depending on a username for crackme5.
 *@argc: Number of arguments passed.
 *@argv: Arguments passed to main.
 *
 *Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	char key[7] = "      ";
	char *username = argv[1];
	size_t length = strlen(username);

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	key[0] = genKeyChar(length, 59);
	key[1] = genKeyChar(calcSumOfChars(username), 79);
	key[2] = genKeyChar(calcProductOfChars(username), 85);

	char maxChar = getMaxChar(username);

	srand(maxChar ^ 14);
	key[3] = genKeyChar(rand(), 63);

	unsigned int sumSquares = 0;

	for (unsigned int i = 0; i < length; i++)
	{
		sumSquares += username[i] * username[i];
	}

	key[4] = genKeyChar(sumSquares, 239);

	char firstChar = username[0];
	unsigned int maxRand = 0;

	for (unsigned int i = 0; i < (unsigned int) firstChar; i++)
	{
		maxRand = rand();
	}

	key[5] = genKeyChar(maxRand, 229);

	printf("%s\n", key);
	return (0);
}

/**
 *genKeyChar - Generates a key character based on a value and XOR.
 *@val: The value to XOR.
 *@xorVal: The XOR value.
 *
 *Return: The generated key character.
 */
char genKeyChar(int val, int xorVal)
{
	return (LOOKUP[(val ^ xorVal) & 63]);
}

/**
 *calcSumOfChars - Calculates the sum of ASCII values in a string.
 *@username: The string to calculate the sum for.
 *
 *Return: The sum of ASCII values.
 */
int calcSumOfChars(char *username)
{
	int sum = 0;
	size_t length = strlen(username);

	for (unsigned int i = 0; i < length; i++)
	{
		sum += username[i];
	}

	return (sum);
}

/**
 *getMaxChar - Finds the maximum ASCII value character in a string.
 *@username: The string to find the maximum character in.
 *
 *Return: The maximum ASCII value character.
 */
char getMaxChar(char *username)
{
	char maxChar = 0;
	size_t length = strlen(username);

	for (unsigned int i = 0; i < length; i++)
	{
		if (username[i] >= maxChar)
		{
			maxChar = username[i];
		}
	}

	return (maxChar);
}

/**
 *calcProductOfChars - Calculates the product of ASCII values in a string.
 *@username: The string to calculate the product for.
 *
 *Return: The product of ASCII values.
 */
unsigned int calcProductOfChars(char *username)
{
	unsigned int product = 1;
	size_t length = strlen(username);

	for (unsigned int i = 0; i < length; i++)
	{
		product *= username[i];
	}

	return (product);
}
