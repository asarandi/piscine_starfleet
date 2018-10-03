#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//translated from pseudo code @ https://en.wikipedia.org/wiki/Quicksort
//nico lomuto partition scheme

int		partition(struct s_art **arts, int lo, int hi)
{
	struct s_art	*pivot, *tempo;
	int				i, j;

	pivot = arts[hi];
	i = lo;

	j = lo;
	while (j < hi - 1)
	{
		if (strcmp(arts[j]->name, pivot->name) < 0)
		{
			tempo = arts[i];
			arts[i] = arts[j];
			arts[j] = tempo;
			i++;
		}
		j++;
	}
	tempo = arts[i];
	arts[i] = arts[hi];
	arts[hi] = tempo;
	return (i);
}

void	ft_quicksort(struct s_art **arts, int lo, int hi)
{
	int	p;

	if (lo < hi)
	{
		p = partition(arts, lo, hi);
		ft_quicksort(arts, lo, p - 1);
		ft_quicksort(arts, p + 1, hi);

	}
}

int	art_count(struct s_art **arts)
{
	int	i = 0;
	while (arts[i])
		i++;
	return (i);
}

void sortArts(struct s_art **arts)
{
	//void	qsort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *));	
//	qsort(arts, art_count(arts), sizeof(struct s_art *), compare_names);
	ft_quicksort(arts, 0, art_count(arts) - 1);

}
