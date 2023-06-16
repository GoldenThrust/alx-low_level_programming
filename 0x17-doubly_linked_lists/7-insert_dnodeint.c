#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: pointer to the first node of dlistint_t
 * @idx: index of node to insert.
 * @n: value of the new node
 * Return: the address of the new node, or NULL if it failed
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *cur_node = *h;
	unsigned int i = 0;

	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (idx == 0)
	{
		if (cur_node != NULL)
			cur_node->prev = new_node;
		new_node->next = *h;
		*h = new_node;
	}
	else
	{
		while (cur_node != NULL && i < idx - 1)
		{
			cur_node = cur_node->next;
			i++;
		}
		if (cur_node == NULL)
		{
			free(new_node);
			return (NULL);
		}
		new_node->prev = cur_node;
		new_node->next = cur_node->next;

		if (cur_node->next != NULL)
			cur_node->next->prev = new_node;

		cur_node->next = new_node;
	}

	return (new_node);
}

