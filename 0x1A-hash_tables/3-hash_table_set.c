#include "hash_tables.h"

/**
 * hash_table_set - that adds an element to the hash table
 * @ht: the hash table you want to add or update the key/value to
 * @key: is the key
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index, i;
	hash_node_t *new_hash;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
	{
		if (!(strcmp(ht->array[i]->key, key)))
		{
			free(ht->array[i]->value);
			ht->array[i]->value = strdup(value);
			return (1);
		}
	}

	new_hash = malloc(sizeof(hash_node_t));

	if (new_hash == NULL)
		return (0);

	new_hash->key = strdup(key);
	new_hash->value = strdup(value);
	new_hash->next = ht->array[index];
	ht->array[index] = new_hash;

	return (1);
}

