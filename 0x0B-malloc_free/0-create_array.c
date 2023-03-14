#include "main.h"
#include <stdlib.h>


/**
 * create_array - create an array of chars, and
 * initializes it with a specifuc char.
 *
 * @size: size of array
 * @c: charater to initialized
 *
 * Return: pointer of an array of chars
 */


char *create_array(unsigned int size, char c)
{
	char *array;

	if (size == 0)
		return (NULL);
	array = malloc(sizeof(c) * size);

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}

