#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to search
 * @accept: string containing the characters to match
 *
 * Return: number of bytes in the initial segment of s which consist only
 * of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;
	int match = 0;

	while (*s)
	{
		match = 0;

		while (*accept)
		{
			if(*s == *accept)
			{
				i++;
				match =  1;
				break;
			}

			accept++;
		}

		if (match == 0)
			break;
		s++;
	}

	return (i);
}

	
