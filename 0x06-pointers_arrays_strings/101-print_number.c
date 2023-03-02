#include "main.h"

/**
  * print_number - Prints any integer with putchar
  * @n: Number to prints
  *
  * Return: Nothing
  */
void print_number(int n)
{
	unsigned int i;

	if (n < 0)
	{
		putchar('-');
		n *= -1;
	}

	i = n;

	if (i / 10)
		print_number(i / 10);

	putchar(i % 10 + '0');
}
