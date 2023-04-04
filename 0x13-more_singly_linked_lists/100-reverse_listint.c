#include "lists.h"

/**
 * reverse_listint - function that reverses a listint_t linked list.
 *
 * @head: pointer to the first node in the lists.
 *
 * Return: pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *cur = *head, *prev = NULL, *next = NULL;

	while (cur != NULL)
	{
		next = cur->next;

		cur->next = prev;

		prev = cur;

		cur = next
	}

	*head = prev;

	return (*head);
}
