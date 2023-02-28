#include "main.h"

/**
 * print_rev - print a string in reverse.
 * @str: string to print.
 *
 */

void print_rev(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	;
	for (i--; i >= 0; i--)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

