#include "lists.h"


/**
 * delete_dnodeint_at_index -  deletes the node at index
 * of a dlistint_t linked list.
 * @head: pointer to the first node of dlistint_t
 * @index: index of node to delete
 * Return: 1 if it succeeded, -1 if it failed
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *cur_node = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = cur_node->next;
		if (*head != NULL)
			(*head)->prev = NULL;

		free(cur_node);
		return (1);
	}

	while (cur_node != NULL && i < index)
	{
		cur_node = cur_node->next;
		i++;
	}

	if (cur_node == NULL)
		return (-1);

	if (cur_node->prev != NULL)
		cur_node->prev->next = cur_node->next;

	if (cur_node->next != NULL)
		cur_node->next->prev = cur_node->prev;

	free(cur_node);
	return (1);
}

