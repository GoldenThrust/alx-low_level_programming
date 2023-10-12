#include "search_algos.h"

/**
 * _binary_search - Searches for a value in a sorted array of integers
 * using binary search algorithmn
 * @array: Pointer to the first element of the array to search in
 * @left: Starting index
 * @right: Ending index
 * @value: Value to search for
 *
 * Return: Index where 'value' is located or -1 if not found
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t cur, mid;

	printf("Value found between indexes [%lu] and [%lu]\n", left, right);

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

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using exponential search algorithmn
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where 'value' is located or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, right, left;

	if (array == NULL)
		return (-1);

	if (array[0] == value)
	{
		printf("Value checked array[0] = [%d]\n", array[0]);
		return (0);
	}

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	left = bound / 2;
	right = (bound < size - 1) ? bound : size - 1;

	return (_binary_search(array, left, right, value));
}

