#include "lists.h"

/**
 * sum_listint - function that returns the sum of all the
 * data (n) of a listint_t linked list.
 *
 * @head: Pointer to the first node.
 *
 * Return: sum of all the data (n).
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	listint_t *cur = head;

	while (cur != NULL)
	{
		sum += cur->n;

		cur = cur->next;
	}

	return (sum);
}

