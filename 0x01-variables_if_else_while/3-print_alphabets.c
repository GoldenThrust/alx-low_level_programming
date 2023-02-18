#include <stdio.h>

/**
 * main - output aplhabet in lowercase and uppercase letters
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char lalpha, ualpha;

	for (lalpha = 'a'; lalpha <= 'z'; lalpha++)
	{
		putchar(lalpha);
	}
	for (ualpha = 'A'; ualpha <= 'Z'; ualpha++)
	{
		putchar(ualpha);
	}
	putchar('\n');

	return (0);
}

