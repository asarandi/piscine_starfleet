#include "header.h"
#include <stdio.h>

int		partition(struct s_player **players, int lo, int hi)
{
	struct	s_player	*temp;
	struct	s_player	*pivot;
	int	i, j;
	
	pivot = players[hi];
	i = lo;
	j = lo;
	while (j <= hi - 1)
	{
		if (players[j]->score > pivot->score)
		{
			temp = players[i];
			players[i] = players[j];
			players[j] = temp;
			i++;
		}
		j++;
	}
	temp = players[i];
	players[i] = players[hi];
	players[hi] = temp;
	return (i);
}

void	quicksort0(struct s_player **players, int lo, int hi)
{
	int	p;

	if (lo < hi)
	{
		p = partition(players, lo, hi);
		quicksort0(players, lo, p - 1);
		quicksort0(players, p + 1, hi);
	}
	return ;
}

int		playersCount(struct s_player **players)
{
	int	i = 0;
	while (players[i] != NULL)
		i++;
	return (i);
}

void	quickSort(struct s_player **players)
{
	int	count = playersCount(players);
	quicksort0(players, 0, count - 1);
	return ;
}
