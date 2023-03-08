#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: int n
 * @i: interger i
 * Return: squares root
 */
int _sqrt(int n, int i);

int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}

/**
 * _sqrt - returns square roots
 * @n: integer n
 * @i: integer i
 * Return: squares root
 */
int _sqrt(int n, int i)
{
	if (n < 0)
		return (-1);
	if ((i * i) > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (_sqrt(n, i + 1));
}

