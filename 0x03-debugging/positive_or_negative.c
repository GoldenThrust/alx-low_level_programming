#include <stdio.h>

/**
 * positive_or_negative - code to check if num is positve,
 * zero or negative
 * @n: number to be test
 */

void positive_or_negative(int n)
{
	if (n > 0)
		printf("%i is positive\n", n);
	else if (n == 0)
		printf("%i is zero\n", n);
	else
		printf("%i is negative\n", n);
}

