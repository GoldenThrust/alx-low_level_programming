#include "list.h"

/**
 * listint_len - function that returns the number
 * of elements in a linked listint_t list.
 *
 * @h: pointer to first node.
 *
 * Return: number of element.
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}

