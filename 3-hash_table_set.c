#include "hash_tables.h"
/**
*hash_table_set - set item in hash table
*@ht: - hash table
*@key: key used to make hashing
*@value: value of item crosponding to key
*Return: 0 on faliure and 1 on success
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i, idx;
	hash_node_t *new;
	char *cp_value;

	if (ht == NULL || *key == "\0" || key == NULL || value || key)
	{
		return (0);
	}

	idx = key_index((const unsigned char *) key, ht->size);
	cp_value = strdup(value);
	if (sp_value == NULL)
		return (0);
	for (i = idx; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value)
			ht->array[i]->value = cp_value;
			return (1);
		}
	}

	new = malloc(sizeof(hash_node_t *));
	if (new == NULL)
	{
		free(cp_value);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = cp_value;
	new->next = ht->array[idx];
	ht->array[idx]->next = new;

	return (1);
}
