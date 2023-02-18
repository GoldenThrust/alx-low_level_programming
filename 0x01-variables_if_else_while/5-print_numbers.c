#include <stdio.h>

/**
 * main - code to print all digit number(0-9)
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	int digit;

	for (digit = 0; digit <= 9; digit++)
	{
		printf("%i", digit);
	}
	printf("\n");

	return (0);
}

