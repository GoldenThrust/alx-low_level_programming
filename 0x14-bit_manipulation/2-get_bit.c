#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: pointer to the number to modify
 * @index: index of the bit to get
 *
 * Return: value of the bit at index, or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= 8 * sizeof(unsigned long int))
		return (-1);

	return ((n >> index) & 1);
}


