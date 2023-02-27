#include "main.h"
/**
 * puts_half - Prints out the first half of a string.
 * @str: input string to print.
 */
void puts_half(char *str)
{
	int i = 0, j;

	while (str[i] != '\0')
		i++;
	if (i + 1 % 2 != '0')
		j = (i - 1) / 2;
	else
		j = (i / 2);
	j++;

	for  (i = j; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
