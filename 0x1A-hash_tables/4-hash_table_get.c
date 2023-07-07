#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: the hash table you want to look into
 * @key: is the key you are looking for
 * Return: the value associated with the element, or NULL
 * if key couldn’t be found
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *new_hash;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	new_hash = ht->array[index];

	while (new_hash && !(strcmp(new_hash->key, key)))
		new_hash = new_hash->next;

	return ((new_hash != NULL) ? new_hash->value : NULL);
}

