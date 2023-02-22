#include "main.h"

/**
 * main - Code to print _putchar, followed by a newline.
 *
 * Return: Always 0 (success)
 */


int main(void)
{
	char str[] = "_putchar";
	int i;

	for (i = 0; i < strlen(str); i++)
		_putchar(str[i]);
	_putchar('\n');

	return (0);
}

