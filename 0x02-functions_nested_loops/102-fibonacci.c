#include <stdio.h>

/**
 * main - Description: prints the first 50 Fibonacci numbers
 *		starting with 1 and 2 folled by a new line
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int i;
	unsigned long a = 0, b = 1, sum;

	for (i = 0; i < 50; i++)
	{
		sum = a + b;
		printf("%lu", sum);

		a = b;
		b = sum;

		if (i == 49)
			printf("\n");
		else
			printf(", ");
	}

	return (0);
}

