#include "header.h"
#include <stdlib.h>
#include <strings.h>


struct	s_node	*newNode()
{
	struct	s_node	*new_node;

	new_node = malloc(sizeof(struct s_node));
	if (new_node == NULL)
		return (NULL);
	bzero(new_node, sizeof(struct s_node));
	new_node->value = 0;
	new_node->random = NULL;
	new_node->next = NULL;
	return (new_node);
}

int				getNodeIndex(struct s_node *start, struct s_node *search)
{
	int	i = 0;
	while (start != NULL)
	{
		if (start == search)
			return (i);
		start = start->next;
		i++;
	}
	return (-1);
}

struct	s_node	*nodeFromIndex(struct s_node *start, int index)
{
	int	i = 0;
	while (i < index)
	{
		start = start->next;
		i++;
	}
	return (start);
}

struct	s_node	*cloneGameBoard(struct s_node *node)
{
	struct	s_node	*clone_ptr1 = NULL;
	struct	s_node	*clone_ptr2 = NULL;
	struct	s_node	*clone_head	= NULL;
	struct	s_node	*node_ptr;
	int				index;


	node_ptr = node;

	while (node_ptr != NULL)
	{
		if (clone_ptr2 == NULL)
			clone_ptr1 = newNode();
		else
		{
			clone_ptr2 = clone_ptr1;
			clone_ptr2->next = newNode();
			clone_ptr1 = clone_ptr2->next;
		}
		if ((clone_ptr2 == NULL) && (node == node_ptr))	//only once
			clone_head = clone_ptr1;

		clone_ptr2 = clone_ptr1;
		clone_ptr1->value = node_ptr->value;

		node_ptr = node_ptr->next;
	}

	node_ptr = node;
	clone_ptr1 = clone_head;

	while (node_ptr != NULL)
	{
		if (node_ptr->random == NULL)
			clone_ptr1->random = NULL;
		else
		{
			index = getNodeIndex(node, node_ptr->random);
			clone_ptr1->random = nodeFromIndex(clone_head, index);
		}
		node_ptr = node_ptr->next;
		clone_ptr1 = clone_ptr1->next;
	}

	return (clone_head);
}
