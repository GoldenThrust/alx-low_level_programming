#include "lists.h"

/**
 * insert_nodeint_at_index - function that inserts a new node
 * at a given position.
 *
 * @head: pointer to the first node.
 * @idx: index of the new node.
 * @n: value of the new node.
 *
 * Return: pointer to the new node, or NULL if it failed.
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_node, *prev_node, *cur_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	prev_node = NULL;
	cur_node = *head;

	for (i = 0; i < idx && cur_node != NULL; i++)
	{
		prev_node = cur_node;
		cur_node = cur_node->next;
	}

	if (i < idx)
	{
		free(new_node);
		return (NULL);
	}

	prev_node->next = new_node;
	new_node->next = cur_node;

	return (new_node);
}
