#include "lists.h"

/**
 * free_listint_safe - function that frees a listint_t list.
 *
 * @h: pointer to the first node.
 *
 * Return: size of the list that was free’d.
 */

size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;

	listint_t *cur, *temp;

	if (h == NULL || *h == NULL)
		return (count);

	cur = *h;

	*h = NULL;

	while (cur != NULL)
	{
		count++;
		
		temp = cur;

		cur = cur->next;

		if (temp < cur)
		{
			free(temp);
		}
		else
		{

			temp->next = NULL;
			
			break;
		}
	}

	return (count);
}
