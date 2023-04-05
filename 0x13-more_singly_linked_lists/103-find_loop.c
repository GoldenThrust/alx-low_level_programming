#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list.
 *
 * @h: pointer to the first node.
 *
 * Return: address of the node where the loop starts, or
 * NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first_h = head, *second_h = head;
	
	while (second_h && second_h->next)
	{
		first_h = first_h->next;

		second_h = second_h->next->next;

		if (first_h == second_h)
		{
			first_h = head;

			while (first_h != second_h)
			{
				first_h = first_h->next;

				second_h = second_h->next;
			}

			return (first_h);
		}
	}
	
	return (NULL);
}
