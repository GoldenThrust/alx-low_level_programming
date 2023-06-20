#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted integer.
 */
int _atoi(char *s)
{
	int sign = 1, calc = 0, i = 0;

	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; s[i] != '\0'; i++)
		calc = calc * 10 + s[i] - '0';

	return (sign * calc);
}
