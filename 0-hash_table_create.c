#include "hash_tables.h"
/**
*hash_table_create - function that create new hash table
*@size: size of hash table's items
*Return: address of new table
*
*/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		ht->array[i] = NULL;
		i++;
	}
	return (ht);
}
