#include "main.h"

/**
 * more_numbers - Print numbers between 0 to 14 ten times.
 */

void more_numbers(void)
{
	int i, j;

	for (i = 0; i <= 9 ; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			if (j > 10)
			_putchar(i / 10 + '0');
		}
		_putchar(i % 10 + '0');
		i++;
	}
	_putchar('\n');
}
