#include "main.h"

/**
 * print_most_numbers - Print numbers between 0 to 9
 * excluding 2 and 4.
 */


void print_most_numbers(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		if (i == 2 || i == 4)
			continue;
		_putchar(i + '0');
	}
	_putchar('\n');
}

