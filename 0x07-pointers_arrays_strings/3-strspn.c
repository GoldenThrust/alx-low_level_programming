#include "main.h"

/**
 * _strspn - gets the
 *           length of a prexif substring
 *
 * @s: pointer to string input
 * @accept: substring prefix to look for
 *
 * Return: the number of bytes in the initial segment
*/

unsigned int _strspn(char *s, char *accept)
{
	int i, j, f;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		f = 1;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				f = 0;
				break;
			}
			j++;
		}
		if (f == 1)
			break;
		i++;
	}

	return (i);
}

