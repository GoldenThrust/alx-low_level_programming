#include <stdio.h>
/**
 * main - prints largest prime factor of 612852475143.
 * Return: Always 0.
 */

int main(void)
{
        long long int a, i;

        a = 612852475143;

        for (i = 2; i <= a; i++)
        {
                if (a % i == 0)
                {
                        a /= i;
                        i--;
                }
        }
        printf("%lld\n", i);
        return (0);
}
