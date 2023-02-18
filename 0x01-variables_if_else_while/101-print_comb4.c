#include <stdio.h>
/**
 * main -code to print possible combination of
 * three number seperated by ", "
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num, num2, num3;

	for (num = 0; num <= 7; num++)
	{
		for (num2 = 0; num2 <= 8; num2++)
		{
			for (num3 = 0; num3 <= 9; num3++)
			{
				if (num != num2 && num != num3 && num2 != num3 &&
					num < num2 && num2 < num3)
				{
					putchar(num + '0');
					putchar(num2 + '0');
					putchar(num3 + '0');

					if (num == 7 && num2 == 8 && num3 == 9)
						continue;

					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');

	return (0);
}

