#include "main.h"

/**
 *  times_table - Function that print  the 9 times table, starting with 0.
 */

void times_table(void)
{
	int num, multi, prod;

	for (num = 0; num <= 9; ++num)
	{
		_putchar('0');
		for (multi = 1; multi <= 9; multi++)
		{
			_putchar(',');
			_putchar(' ');

			prod = num * multi;
			if (prod <= 9)
				_putchar(' ');
			else
				_putchar((prod / 10) + '0');
			_putchar((prod % 10) + '0');
		}
		_putchar('\n');
	}
}

