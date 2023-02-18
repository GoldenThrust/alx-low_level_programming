#include <stdio.h>

/**
 * main - code to print all digit number(0-9) using putchar.
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	int digit;

	for (digit = 0; digit <= 9; digit++)
	{
		putchar(digit + '0');
	}
	putchar('\n');

	return (0);
}

