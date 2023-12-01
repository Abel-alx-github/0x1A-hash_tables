#include "hash_tables.h"
/**
*hash_table_get - retrive value crosponding to key in ht
*@ht: hash table
*@key: key used for hashing
*Return: value on success otherwise nuil
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;

	if (ht == NULL || key == NULL)
		return (NULL);
	idx = key_index((const unsigned char *) key, ht->size);
	if (ht->array[idx])
	{
		if (strcmp(ht->array[idx]->key, key) == 0)
			return (ht->array[idx]->value);
		while (ht->array[idx]->next)
		{
			if (strcmp(ht->array[idx]->key, key) == 0)
				return (ht->array[idx]->value);
			ht->array[idx] = ht->array[idx]->next;

		}
	}
	return (NULL);
}
