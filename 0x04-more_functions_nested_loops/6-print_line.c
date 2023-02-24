#include "main.h"

/**
 * print_line - Function that draw line depending on int n.
 * @n : The number of time _ will be draw
 */

void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		_putchar('_');
	}

	_putchar('\n');
}

