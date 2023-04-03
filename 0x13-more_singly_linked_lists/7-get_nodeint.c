#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the nth node
 * of a listint_t linked list
 *
 * @head: Pointer to the first node.
 * @index: Index of the node.
 * Return: A pointer to the nth node, or NULL if the node does not exist.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	listint_t *cur = head;

	for (i = 0; cur != NULL && i < index; i++)
		cur = cur->next;

	return (cur);
}
