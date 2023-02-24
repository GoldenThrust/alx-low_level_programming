#include "main.h"
#include <stdio.h>

/**
 * main - print number from 0 to 100. fizz for multiple of 3
 *buzz for 5 mult and fizzbuzz for both.
 * Return: Always 0
 */
int main(void)
{
	int i = 1;

	while (i < 101)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			printf("%s", "FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			printf("%s", "Fizz");
		}
		else if (i % 5 == 0)
		{
			printf("%s", "Buzz");
		}
		else
		{
			printf("%d", i);
		}

		if (i != 100)
		{
		printf(" ");
		}
		i++;
	}
	printf("\n");
	return (0);
}

