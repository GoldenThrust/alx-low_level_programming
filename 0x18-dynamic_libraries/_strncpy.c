#include "main.h"

/**
 * _strncpy - copies @n bytes of the string from src to dest
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to copy
 *
 * Return: pointer to the destination string dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *n_dest = dest;

	while (*src && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}

	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}

	return (n_dest);
}
