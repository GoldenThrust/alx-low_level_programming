#include "main.h"


/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if equal, -1 otherwise
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		s1++;
		s2++;
		if (*s1 != *s2)
			return (-1);
	}

	return (0);
}
