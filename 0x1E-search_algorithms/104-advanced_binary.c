#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * using advance binary search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where 'value' is located or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1;

	if (array == NULL)
		return (-1);

	return (rec_binary_search(array, left, right, value));
}

/**
 * rec_binary_search - Searches for a value in a sorted array of integers
 * using binary search algorithmn
 * @array: Pointer to the first element of the array to search in
 * @left: Starting index
 * @right: Ending index
 * @value: Value to search for
 *
 * Return: Index where 'value' is located or -1 if not found
 */
int rec_binary_search(int *array, size_t left, size_t right, int value)
{
	size_t cur, mid;

	if (left <= right)
	{
		printf("Searching in array: ");
		for (cur = left; cur < right; cur++)
			printf("%i, ", array[cur]);

		printf("%i\n", array[cur]);

		mid = left + (right - left) / 2;

		if (array[mid] == value)
		{
			if (mid > left)
				return (rec_binary_search(array, left, mid, value));
			return (mid);
		}

		if (array[mid] <= value)
			return (rec_binary_search(array, mid + 1, right, value));
		else
			return (rec_binary_search(array, left, mid - 1, value));
	}

	return (-1);
}

