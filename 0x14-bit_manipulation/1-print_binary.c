#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;

	unsigned int size = sizeof(unsigned long int) * 8;

	int i, leading_zero = 1;

	mask <<= size - 1;
	for (i = 0; i < (int)size; i++)
	{
		if ((n & mask) == 0 && leading_zero)
			;
		else
		{
			_putchar((n & mask) ? '1' : '0');
			leading_zero = 0;
		}

		mask >>= 1;

	}

	if (leading_zero)
		_putchar('0');
}

