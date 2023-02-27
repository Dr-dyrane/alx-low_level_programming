#include "main.h"
/**
 * print_rev - reverse the characters in a string and print them
 * @s: pointer character of string
 * @rev -variable to store reverser characters
 * Return: reversed string
 */
void print_rev(char *s)
{
	char rev[1000];
	int index, j, count = 0;

	while (s[count] != '\0')
	{
		count++;
	}
	j = count - 1;

	for (index = 0; index < count; index++)
	{
		rev[index] = s[j];
		j--;
		_putchar(rev[index]);
	}
	_putchar('\n');
}
