#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: The hash table
*/
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp_hash, *state_hash;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] == NULL)
			continue;

		tmp_hash = ht->array[i];
		while (tmp_hash)
		{
			state_hash = tmp_hash->next;
			free(tmp_hash->key);
			free(tmp_hash->value);
			free(tmp_hash);
			tmp_hash = state_hash;
		}
	}

	free(ht->array);
	free(ht);
}

