#include "function_pointer.h"
#include<stdlib.h>

/**
 * print_name - print name
 *
 * @name: name to print
 * @f: function pointer that doesn't return anything
 *
 * Return: Always 0 (Success)
*/

void print_name(char *name, void (*f)(char *))
{
	if (f != NULL)
		f(name);
}
