#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: length of hash table
 * Return: A pointer to the newly created hash table
 * on failure return NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table = malloc(sizeof(shash_table_t));
	unsigned long int i;

	if (table == NULL)
		return (NULL);
	table->size = size;
	table->shead = NULL;
	table->stail = NULL;
	table->array = calloc(table->size, sizeof(shash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	for (i = 0; i < table->size; i++)
		table->array[i] = NULL;

	return (table);
}

/**
 * set_shash_a - set hash table position
 * @ht: the hash table you want to add or update the key/value to
 * @new_hash: temporary hash table
 * @key: is the key
*/
void set_shash_a(shash_table_t *ht, shash_node_t *new_hash, const char *key)
{
	shash_node_t *tmp_hash;

	if (ht->shead == NULL && ht->stail == NULL)
	{
		new_hash->sprev = NULL;
		new_hash->snext = NULL;
		ht->shead = new_hash;
		ht->stail = new_hash;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		tmp_hash = ht->shead;
		while (tmp_hash->sprev && strcmp(tmp_hash->sprev->key, key) > 0)
			tmp_hash = tmp_hash->sprev;
		new_hash->sprev = tmp_hash->sprev;
		new_hash->snext = tmp_hash;
		if (tmp_hash->sprev == NULL)
			ht->shead = new_hash;
		else
			tmp_hash->snext->sprev = new_hash;

		tmp_hash->sprev = new_hash;
	}
	else
	{
		tmp_hash = ht->shead;
		while (tmp_hash->snext && strcmp(tmp_hash->snext->key, key) < 0)
			tmp_hash = tmp_hash->snext;
		new_hash->sprev = tmp_hash;
		new_hash->snext = tmp_hash->snext;
		if (!(tmp_hash->snext))
			ht->stail = new_hash;
		else
			tmp_hash->snext->sprev = new_hash;

		tmp_hash->snext = new_hash;
	}
}

/**
 * shash_table_set - that adds an element to the sorted hash table
 * @ht: the hash table you want to add or update the key/value to
 * @key: the key
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index, i;
	shash_node_t *new_hash;

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
	new_hash = malloc(sizeof(shash_node_t));
	if (new_hash == NULL)
		return (0);
	new_hash->key = strdup(key);
	new_hash->value = strdup(value);
	new_hash->next = ht->array[index];
	ht->array[index] = new_hash;

	set_shash_a(ht, new_hash, key);

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key.
 * @ht: the hash table you want to look into
 * @key: is the key you are looking for
 * Return: the value associated with the element, or NULL
 * if key couldn’t be found
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *new_hash;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	new_hash = ht->array[index];

	while (new_hash && strcmp(new_hash->key, key) != 0)
		new_hash = new_hash->next;

	return ((new_hash != NULL) ? new_hash->value : NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: The hash table
*/
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *new_hash;

	if (ht == NULL)
		return;

	new_hash = ht->shead;

	printf("{");

	while (new_hash)
	{
		printf("'%s': '%s'", new_hash->key, new_hash->value);
		new_hash = new_hash->snext;

		if (new_hash)
			printf(", ");
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - prints a reversed sorted hash table
 * @ht: The hash table
*/
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *new_hash;

	if (ht == NULL)
		return;

	new_hash = ht->stail;

	printf("{");

	while (new_hash)
	{
		printf("'%s': '%s'", new_hash->key, new_hash->value);
		new_hash = new_hash->sprev;

		if (new_hash)
			printf(", ");
	}

	printf("}\n");
}

/**
 * shash_table_delete - deletes a hash table
 * @ht: The hash table
*/
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp_hash, *state_hash;

	tmp_hash = ht->shead;
	while (tmp_hash)
	{
		state_hash = tmp_hash->next;
		free(tmp_hash->key);
		free(tmp_hash->value);
		free(tmp_hash);
		tmp_hash = state_hash;
	}

	free(ht->array);
	free(ht);
}

