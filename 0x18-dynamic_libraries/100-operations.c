/**
 *add - Adds two integers.
 *@a: The first integer.
 *@b: The second integer.
 *
 *Return: The sum of the two integers.
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 *sub - Subtracts one integer from another.
 *@a: The first integer.
 *@b: The second integer.
 *
 *Return: The difference between the two integers.
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 *mul - Multiplies two integers.
 *@a: The first integer.
 *@b: The second integer.
 *
 *Return: The product of the two integers.
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 *div - Divides one integer by another.
 *@a: The numerator.
 *@b: The denominator.
 *
 *Return: The quotient of the division, or 0 if the denominator is zero.
 */
int div(int a, int b)
{
	return (a / b);
	/*if (b != 0)
		return (a / b);
	return (0);*/
}

/**
 *mod - Calculates the modulo of one integer by another.
 *@a: The dividend.
 *@b: The divisor.
 *
 *Return: The remainder of the modulo operation, or 0 if the divisor is zero.
 */
int mod(int a, int b)
{
	return (a % b);
	/*if (b != 0)
		return (a % b);
	return (0);*/
}
