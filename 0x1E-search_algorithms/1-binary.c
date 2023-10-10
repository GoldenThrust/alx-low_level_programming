#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array of integers
 * using binary search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where 'value' is located or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, cur, mid;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		printf("Searching in array: ");
		for (cur = left; cur < right; cur++)
			printf("%i, ", array[cur]);
		printf("%i\n", array[cur]);

		mid = (left + right) / 2;

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}

