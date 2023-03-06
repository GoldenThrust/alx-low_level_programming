#include "main.h"

/**
 * _memset - fills memory with constant byte.
 *
 * @s: pointer to memory to be fill
 *
 * @b: character to fill
 *
 * @n: number of byte to fill
 *
 * Return: pointer to the filled memory area
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}

