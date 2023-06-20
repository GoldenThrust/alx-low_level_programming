#include "main.h"

/**
 * _memset - fills @n bytes of the memory area by @s with constant byte @b
 * @s: memory area to be filled
 * @b: character to fill the memory area with
 * @n: number of bytes to be filled
 *
 * Return: pointer to the filled memory area @s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *mem = s;

	while (n > 0)
	{
		*s = b;
		s++;
		n--;
	}

	return (mem);
}
