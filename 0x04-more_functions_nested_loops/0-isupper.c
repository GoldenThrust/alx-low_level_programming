#include "main.h"

/**
 * _isupper - check if c is an uppercase letter
 * @c: Int representing character
 * Return: Always 0.
 */



int _isupper(int c)
{
	if (c >= 'A' or c <= 'Z')
	{
		return (1);
	}
	return (0);
}

