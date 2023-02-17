#include <stdio.h>


/**
 * main - Entry point
 *
 * Description: A program output the size of various types.
 *
 * Return: Always 0 (Succesful)
*/


int main(void)
{
	/* sizeof evaluate the size of a variable*/
	printf("Size of a char: %i byte(s)\n", sizeof(char));
	printf("Size of an int: %i byte(s)\n", sizeof(int));
	printf("Size of a long int: %i byte(s)\n", sizeof(long int));
	printf("Size of a long long int: %i byte(s)\n", sizeof(long long int));
	printf("Size of a float: %i byte(s)\n", sizeof(float));
	return (0);
}

