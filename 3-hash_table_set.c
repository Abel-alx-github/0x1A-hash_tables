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
	unsigned long int idx;
	hash_node_t *new, *temp;

	if (ht == NULL)
	{
		return (0);
	}

	new = malloc(sizeof(hash_node_t *));
	if (new == NULL)
		return (0);
	new->key = (char *) key;
	new->value = (char *) value;
	new->next = NULL;

	idx = key_index((const unsigned char *) key, ht->size);
	if (ht->array[idx] == NULL)
	{
		ht->array[idx] = new;
	}
	else if (ht->array[idx]->key == key)
	{
		ht->array[idx]->value = (char *)value;
	}
	else
	{

		if (ht->array[idx]->next == NULL)
		{
			ht->array[idx]->next = new;
		}
		else
		{
			temp = ht->array[idx]->next;
			ht->array[idx]->next = new;
			new->next = temp;
		}
	}

	return (1);
}
