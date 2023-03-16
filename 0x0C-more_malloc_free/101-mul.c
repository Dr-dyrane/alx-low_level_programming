#include "main.h"
#include <stdlib.h>

/**
 * _isdigit - checks if a character is a digit
 *
 * @c: the character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * mul - multiplies two positive numbers
 *
 * @num1: the first number to multiply
 * @num2: the second number to multiply
 *
 * Return: a pointer to the product of num1 and num2
 */
char *mul(char *num1, char *num2)
{
	int len1, len2, i, j, product, carry;
	char *result;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (result == NULL)
		return (NULL);
	for (i = 0; i < len1 + len2; i++)
		result[i] = '0';
	result[i] = '\0';
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			product = (num1[i] - '0') * (num2[j] - '0') +
				(result[i + j + 1] - '0') + carry;
			carry = product / 10;
			result[i + j + 1] = (product % 10) + '0';
		}
		result[i] += carry;
	}
	for (i = 0; i < len1 + len2; i++)
	{
		if (result[i] != '0')
			break;
	}
	if (i == len1 + len2)
		return ("0");
	return (result + i);
}

/**
 * main - multiplies two positive numbers
 *
 * @argc: the number of arguments passed to the program
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *product;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}
	num1 = argv[1];
	num2 = argv[2];
	while (*num1)
	{
		if (!_isdigit(*num1))
		{
			printf("Error\n");
			return (98);
		}
		num1++;
	}
	while (*num2)
	{
		if (!_isdigit(*num2))
		{
			printf("Error\n");
			return (98);
		}
		num2++;
	}
	product = mul(argv[1], argv[2]);
	printf("%s\n", product);
	free(product);
	return (0);
}
