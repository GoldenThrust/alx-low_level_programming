#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: The hash table
*/
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	short flag = 0;
	hash_node_t *new_hash;

	if (ht == NULL)
		return;

	putchar('{');
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] == NULL)
			continue;

		if (flag)
			printf(", ");

		new_hash = ht->array[i];
		while (new_hash)
		{
		printf("'%s': '%s'", new_hash->key, new_hash->value);
		new_hash = new_hash->next;
		if (new_hash)
			printf(", ");
		}
		flag = 1;
	}
	puts("}");
}

