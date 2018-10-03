#include "header.h"
#include <string.h>
#include <stdlib.h>

/*
# define CS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !?:;,.$&<>()+*-_="

struct s_node {
	char c;
	struct s_node *prev;
	struct s_node *next;
};
*/

struct s_node *one_ring_to_rule_them_all(void)
{
	struct s_node	*node0;
	struct s_node	*node1;

	struct s_node	*start;

	unsigned long i = 0;
	
	while (i < strlen(CS))
	{
		node0 = malloc(sizeof(struct s_node));
		bzero(node0, sizeof(struct s_node));
		if (i == 0)
			start = node0;

		node0->c = CS[i];
		
		node1 = start;
		while (node1->next != NULL)
			node1 = node1->next;
		if (i > 0)
		{
			node1->next = node0;
			node0->prev = node1;
		}
		i++;
	}

	node1 = start;
	while (node1->next != NULL)
		node1 = node1->next;
	node1->next = start;
	start->prev = node1;

	return (start);


}

char *precious(int *text, int size)
{
	struct s_node	*ring0;
	char			*decoded;
	int				i, j;

	ring0 = one_ring_to_rule_them_all();
	i = 0;

	decoded = malloc(size + 1);
	bzero(decoded, size + 1);

	while (i < size)
	{
		j = text[i];

		while (j > 0)
		{
			ring0 = ring0->next;
			j--;
		}
		while (j < 0)
		{
			ring0 = ring0->prev;
			j++;
		}
		decoded[i] = ring0->c;
		i++;
	}
	return (decoded);
}
