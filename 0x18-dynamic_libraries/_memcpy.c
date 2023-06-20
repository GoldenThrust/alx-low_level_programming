#include "main.h"

/**
 * _memcpy - copies @n bytes from memory @src to memory @dest
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes to copy
 *
 * Return: pointer to the destination memory @dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *mem = dest;

	while (n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}

	return (mem);
}

