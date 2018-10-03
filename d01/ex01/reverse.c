#include "header.h"
#include <stdio.h>

void recu0(struct s_node *lst)
{
	if (lst->next != NULL)
	{
		recu0(lst->next);
		printf(" ");
	}
	printf("%s", lst->word);
	return ;
}

void printReverse(struct s_node *lst)
{
	recu0(lst);
	printf("\n");
	return ;
}
