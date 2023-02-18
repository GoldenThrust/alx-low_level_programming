#include <stdio.h>
/**
 * main -code to print possible combination of
 * two number seperated by ", "
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num, num2;

	for (num = 0; num <= 9; num++)
	{
		for (num2 = 0; num2 <= 9; num2++)
		{
			putchar(num + '0');
			putchar(num2 + '0');

			if (num == 9 && num2 == 9)
				continue;

			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}

