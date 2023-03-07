#include "main.h"

/**
 * _memcpy - copies memory area
 *
 * @dest: where we will copy to
 * @src: what we are to copy
 * @n: bytes of @src
 *
 * Return: Always 0 (Success)
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
