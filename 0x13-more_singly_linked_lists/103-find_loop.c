#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list.
 *
 * @h: pointer to the first node.
 *
 * Return: address of the node where the loop starts, or
 * NULL if there is no loop
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *cur, *temp;

	size_t count = 0;

	if (!h || !(*h))
		return (0);

	cur = *h;

	*h = NULL;

	while (cur)
	{
		count++;

		if (cur->next >= current)
		{
			temp = cur;
			
			cur = cur->next;
			
			free(temp);
		}
		else
		{
			free(cur);
			
			break;
		}
	}
	
	return (count);
}
