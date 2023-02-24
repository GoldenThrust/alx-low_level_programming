#include "main.h"

/**
 * _isdigit - Check if digit is (0-9)
 * @c: function parameter that hold the character
 *
 * Return: Always 0.
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

