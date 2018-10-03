#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_stack *stackInit(void)
{
	struct s_stack	*stack;

	if ((stack = malloc(sizeof(struct s_stack))) == NULL)
		return (NULL);
	stack->item = NULL;
	return (stack);
}

void *pop(struct s_stack *stack)
{
	struct	s_item *result;
	char	*word;

	if ((stack == NULL) || (stack->item == NULL))
		return (NULL);
	result = stack->item;
	stack->item = result->next;
	word = result->word;
	free(result);
	return (word);
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *ptr;

	if (stack == NULL)
		return ;
	ptr = malloc(sizeof(struct s_item));
	ptr->word = word;
	ptr->next = stack->item;
	stack->item = ptr;
	return ;
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack	*stack;
	struct s_node	*original_lst;
	char			*word;

	if (lst == NULL)
		return ;

	original_lst = lst;

	if ((stack = stackInit()) == NULL)
		return ;

	while (lst != NULL)
	{
		push(stack, lst->word);
		lst = lst->next;
	}

	while (1)
	{
		word = (char *)pop(stack);
		if (word == NULL)
		{
			printf("\n");
			break ;
		}
		printf("%s", word);
		if (word != original_lst->word)
			printf(" ");
	}
	free(stack);
	return ;
}

