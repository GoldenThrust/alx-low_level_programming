#include "main.h"

/**n - Function that prints 10x alphabet,
 * in lowercase
 */

void print_alphabet_x10(void)
{
	int j, i;

	for (j = 0; j <= 9; j++)
	{
		for (i = 'a'; i <= 'z'; i++)
			_putchar(i);
		_putchar('\n');
	}
}

