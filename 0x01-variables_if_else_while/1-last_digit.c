#include <stdlib.h>
#include <time.h>
/* more headers goes there */
#include <stdio.h>

/* betty style doc for function main goes there */
/**
 * main - code to check if num is greater than 5,
 * less than 6 or equal to0.
 *
 * Return: Always O (Success)
 */

int main(void)
{
	int n, digit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	/* your code goes there */
	digit = n % 10; /* store last digit */

	if (digit > 5)
		printf("Last digit of %i is %i and is greater than 5\n", n, digit);
	else if (digit == 0)
		printf("Last digit of %i is %i and is 0\n", n, digit);
	else
		printf("Last digit of %i is %i and is less than 6 and not 0\n", n, digit);

	return (0);
}

