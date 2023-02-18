#include <stdio.h>
/**
 * main - code to output all base 16 number.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num, alpha;

	for (num = 0; num <= 9; num++)
		putchar(num + '0');
	for (alpha = 'a'; alpha <= 'f'; alpha++)
		putchar(alpha);

	putchar('\n');

	return (0);
}

