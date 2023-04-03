#include "list.h"

/**
 * add_nodeint_end - function that adds a new node at the end
 * of a listint_t list.
 *
 * @head: pointer to the first node.
 * @n: value to add to the list
 *
 * Return: Address of the new node.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	listint_t *current_node = *head;

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;

		return (new_node);
	}

	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}

	current_node->next = new_node;

	return (new_node);
}


