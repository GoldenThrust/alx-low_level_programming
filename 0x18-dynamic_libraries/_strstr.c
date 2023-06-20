#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: string to search
 * @needle: string to find
 *
 * Return: pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *s = haystack;
		char *f = needle;

		while (*haystack && *f && *haystack == *f)
		{
			haystack++;
			f++;
		}

		if (!*f)
			return (s);

		haystack = s + 1;
	}

	return (NULL);
}
