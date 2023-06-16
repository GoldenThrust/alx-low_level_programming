#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: pointer to the first node of dlistint_t
*/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *cur;

	while (head != NULL)
	{
		cur = head->next;
		free(head);
		head = cur;
	}
}

