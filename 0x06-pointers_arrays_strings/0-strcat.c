#include "main.h"

/**
 * _strcat - concatenates
 *          two strings.
 *
 * @dest: pointer to destnation input
 * @src: pointer to source input
 *
 * Return: pointer to resulting string @dest
*/

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;

	while (dest[i])
		i++;

	for (j = 0; src[j] ; j++)
		dest[i++] = src[j];

	return (dest);
}
