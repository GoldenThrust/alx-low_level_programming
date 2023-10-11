#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 * using jump search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where 'value' is located or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump = sqrt(size), right = 0, left = 0, i;

	if (array == NULL)
		return (-1);

	while (right < size)
	{
		printf("Value checked array[%li] = [%i]\n", right, array[right]);
		right = (right + jump <= size) ? right + jump : size;

		if (array[right] >= value)
		{
			printf("Value found between indexes [%li] and [%li]\n", left, left + jump);
			for (i = left; i <= left + jump && i < size; i++)
			{
				printf("Value checked array[%li] = [%i]\n", i, array[i]);

				if (array[i] == value)
					return (i);
			}

			return (-1);
		}
		left = right;
	}
	return (-1);
}

