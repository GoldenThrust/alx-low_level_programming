#include "main.h"

/**
 * print_numbers - Print numbers between 0 to 9.
 */


void print_numbers(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		_putcahr(i + '0');
	}
	_putchar('\n');
}

