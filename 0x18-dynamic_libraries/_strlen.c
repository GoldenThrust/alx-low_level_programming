#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to measure the length of
 *
 * Return: length of the string.
 */
int _strlen(char *s)
{
	int l = 0;

	while (*s)
	{
		l++;
		s++;
	}

	return (l);
}
