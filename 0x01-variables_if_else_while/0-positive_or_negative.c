#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - prints whether the number stored in the variable n is positive or negative
 *
 * Return:0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	printf("%d\n", n);
	if (n > 0)
		printf("%s\n", "is positive");
	else if (n == 0)
		printf("%s\n", "is zero");
	else
		printf("%s\n", "is negative");

	return (0);
}
