#include "lists.h"

/**
 * get_dnodeint_at_index - find the nth node of a dlistint_t linked list
 * @head: pointer to the first node of dlistint_t
 * @index: index of node to fetch.
 * Return: pointer to the nth node, or NULl
 * if node does not exit
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	size_t i;

	if (head == NULL)
		return (NULL);
	if (index == 0)
		return (head);

	for (i = 0; i < index; i++)
	{
		if (head->next == NULL)
			return (NULL);
		head = head->next;
	}

	return (head);
}

