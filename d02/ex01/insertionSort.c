#include "header.h"
#include <stdio.h>

void	insertionSort(struct s_player **players)
{
	int i, j;
	struct s_player	*temp;

	i = 1;
	while (players[i] != NULL)
	{
		j = i;
		while ((j > 0) && (players[j - 1]->score < players[j]->score))	//descending order
		{
			temp = players[j];
			players[j] = players[j - 1];
			players[--j] = temp;
		}
		i++;
	}
	return ;
}
