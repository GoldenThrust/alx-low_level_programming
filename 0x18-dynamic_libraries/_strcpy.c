#include "main.h"

/**
 * _strcpy - copies the string pointed to by src to dest
 * @dest: destination buffer
 * @src: source string
 *
 * Return: pointer to the destination string dest.
 */
char *_strcpy(char *dest, char *src)
{
	char *n_dest = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (n_dest);
}
