#include "lists.h"

/**
 * sum_dlistint - calculate the sum of all the data (n)
 * of a dlistint_t linked list.
 * @head: pointer to the first node of dlistint_t
 * Return: the sum of all the data(n) of a dlistint_t linked list.
*/
int sum_dlistint(dlistint_t *head)
{
	unsigned int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}

