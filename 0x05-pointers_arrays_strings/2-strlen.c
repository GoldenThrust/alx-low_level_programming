#include "main.h"

/**
 * _strlen - Calculate the lenght of a string
 *
 * @s: string to calculate.
 *
 * Return: string lenght
 *
 */

int _strlen(char *s)
{
	int i, strlenght;

	for (i = 0; s[i] != '\0'; i++)
	{
		strlenght++;
	}
	return (strlenght);
}

