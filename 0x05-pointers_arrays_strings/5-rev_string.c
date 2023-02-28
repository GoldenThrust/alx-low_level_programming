#include "main.h"

/**
 * rev_string - reverses a string
 *
 * @s: string parameter input
 */

void rev_string(char *s)
{
	int j, i;
	char k;

	for (j = 0; s[j] != '\0'; ++j)
		;

	for (i = 0; i < j / 2; ++i)
	{
		k = s[i];

		s[i] = s[j - i - 1];
		s[j - 1 - i] = k;
	}
}

