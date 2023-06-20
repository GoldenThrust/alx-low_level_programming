#include "main.h"

/**
 * _strchr - locates the first occurrence of a character in a string
 * @s: string to search
 * @c:  character to locate
 *
 * Return: pointer to the first occurrence of
 * the character @c in the string @s,
 * or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);

		s++;
	}

	if (*s == c)
	{
		return (s);
	}

	return (NULL);
}

