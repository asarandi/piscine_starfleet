//hash stdin; print to stdout

#include <stdlib.h>
#include <strings.h>
#include "header.h"

// FNV-1a
size_t hash(char *input)
{
	unsigned int fnw_prime = 16777619;
	unsigned int hash = 2166136261;
	int	i = 0;
	while (input[i])
	{
		hash ^= input[i];
		hash *= fnw_prime;
		i++;
	}
	return ((size_t)hash);
}

struct s_dict *dictInit(int capacity)
{
	struct s_dict	*dict;

	dict = malloc(sizeof(struct s_dict));
	if (dict == NULL)
		return (NULL);
	bzero(dict, sizeof(struct s_dict));
	dict->capacity = capacity;
	dict->items = malloc((capacity + 1) * sizeof(struct s_item *));
	if (dict->items == NULL)
		return (NULL);
	bzero(dict->items, (capacity + 1) * sizeof(struct s_item *));
	return (dict);
}

int dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	struct s_item	*item;

	item = malloc(sizeof(struct s_item));
	if (item == NULL)
		return (0);
	item->key = key;
	item->value = value;
	item->next = NULL;

	size_t	hash0 = hash(key);
	size_t	index = hash0 % dict->capacity;

	struct s_item *ptr;

	ptr = dict->items[index];
	if (ptr == NULL)
	{
		dict->items[index] = item;
	}
	else
	{
		while ((ptr != NULL) && (ptr->next != NULL))
			ptr = ptr->next;
		ptr->next = item;
	}
	return (1);
}

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
	size_t hash0 = hash(key);
	size_t index = hash0 % dict->capacity;
	struct s_item	*ptr;

	ptr = dict->items[index];
	while (ptr != NULL)
	{
		if (strcmp(ptr->key, key) == 0)
		{
			return (ptr->value);
		}
		else
		{
			ptr = ptr->next;
		}
	}
	return (NULL);
}

int searchPrice(struct s_dict *dict, char *name)
{
	struct s_art	*painting;

	painting = dictSearch(dict, name);
	if (painting != NULL)
	{
		return (painting->price);
	}
	return (-1);
}
