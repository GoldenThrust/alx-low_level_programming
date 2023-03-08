#include "main.h"

/**
 * factorial - finds the factorial of *n
 *
 * @n: int to find factorial
 *
 * Return: factorial of @n
*/
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}

