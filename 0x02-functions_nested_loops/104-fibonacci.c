#include <stdio.h>

/**
 * main - finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2
 * followed by a new line.
 * Return: Always 0 (success)
*/

int main(void)
{
	unsigned long int a, b, c, d, e, f, g;

	b = 1;
	c = 2;

	printf("%lu", b);

	for (a = 1; a < 91; a++)
	{
		printf(", %lu", c);
		c = c + b;
		b = c - b;
	}
	d = b / 1000000000;
	e = b % 1000000000;
	f = c / 1000000000;
	g = c % 1000000000;

	for (a = 92; a < 99; ++a)
	{
		printf(", %lu", f + (g / 1000000000));
		printf("%lu", g % 1000000000);
		f = f + d;
		d = f - d;
		g = g + e;
		e = g - e;
	}
	printf("\n");
	return (0);
}
