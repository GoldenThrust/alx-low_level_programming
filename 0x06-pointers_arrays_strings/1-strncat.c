#include "main.h"

/**
 * _strncat - Concatenate two strings.
 *
 * @dest: pointer to destination input
 *
 * @src: pointer to source input
 * @n: most number of bytes from @src
 *
 * Return: @dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int h, i;

	h = 0;

	while (dest[h])
		h++;


	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[h + i] = src[i];
	dest[h + i] = '\0';

	return (dest);
}

