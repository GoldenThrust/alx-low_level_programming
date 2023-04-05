#include "lists.h"

/**
 * print_listint_safe - function that prints a listint_t linked list.
 *
 * @head: pointer to the first node.
 *
 * Return: number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;

	size_t count = 0;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;

		current = current->next;

		if (current >= head && current != NULL)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			exit(98);
		}
	}

	return (count);
}
