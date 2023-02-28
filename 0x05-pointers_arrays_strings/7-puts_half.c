#include "main.h"

/**
 * puts_half - prints half of a string
 *
 * @str: string parameter input
 *
*/

void puts_half(char *str)
{
	int i, j, k;

	for (i = 0; str[i] != '\0'; i++)
		;
	j = (i - 1) / 2;
	for (k = j + 1; str[k] != '\0'; k++)
	{
		_putchar(str[k]);
	}
	_putchar('\n');
}
