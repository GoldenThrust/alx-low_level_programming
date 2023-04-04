#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node
 * at index index of a listint_t linked list
 *
 * @head: Pointer to the first node.
 * @index: Index of the node to be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *cur, *prev;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		cur = *head;
		*head = (*head)->next;
		free(cur);
		return (1);
	}

	prev = *head;

	cur = (*head)->next;

	for (i = 1; cur != NULL && i < index; i++)
	{
		prev = cur;
		cur = cur->next;
	}

	if (cur == NULL)
		return (-1);

	prev->next = cur->next;
	free(cur);

	return (1);
}

