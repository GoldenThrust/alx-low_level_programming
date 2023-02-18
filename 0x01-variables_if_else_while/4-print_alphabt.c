#include <stdio.h>

/**
 * main - output aplhabet in lowercase and uppercase letters
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char alpha;

	for (alpha = 'a'; alpha <= 'z'; alpha++)
	{
		if (alpha == 'e' || alpha == 'q')
			continue;
		putchar(alpha);
	}
	putchar('\n');

	return (0);
}

