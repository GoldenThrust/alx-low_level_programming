#include "main.h"

/**
 * _puts - writes a string to stdout
 * @s: string to write
 */
void _puts(char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}

	_putchar('\n');
}
