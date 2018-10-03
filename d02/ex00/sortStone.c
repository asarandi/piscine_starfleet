#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int		countUnique(struct s_stone *stone)
{
	if (stone == NULL)
		return (0);
	int	k = stone->size;
	int	count = 1;
	while (stone)
	{
		if (stone->size != k)
		{
			k = stone->size;
			count++;
		}
		stone = stone->next;
	}
	return (count);
}

void	copyUnique(struct s_stone **dst, struct s_stone *stone)
{
	if (stone == NULL)
		return ;
	int i = 0;
	dst[i] = stone;
	while (stone)
	{
		if (stone->size != dst[i]->size)
			dst[++i] = stone;
		stone = stone->next;
	}
	dst[++i] = NULL;
	return ;
}

void	bubbleSortPointers(struct s_stone **ptrs, int count)
{
	struct	s_stone	*temp;
	int	swapped;
	int	i;
	while (1)
	{
		swapped = 0;
		i = 1;
		while (i <= count - 1)
		{
			if (ptrs[i - 1]->size > ptrs[i]->size)
			{
				temp = ptrs[i - 1];
				ptrs[i - 1] = ptrs[i];
				ptrs[i] = temp;
				swapped = 1;
			}
			i++;
		}
		if (swapped == 0)
			break ;
	}
	return ;
}

void	fixPointers(struct s_stone **sorted)
{
	struct	s_stone	*ptr;
	int	i = 0;

	while (sorted[i] != NULL)
	{
		ptr = sorted[i];
		while ((ptr->next != NULL) && (ptr->next->size == ptr->size))
			ptr = ptr->next;
		i++;
		ptr->next = sorted[i];
	}
	ptr->next = NULL;
}

void	sortStones(struct s_stone **stone)
{
	if ((stone == NULL) || (stone[0] == NULL))
		return ;
	int	unique_count = countUnique(stone[0]);
	struct s_stone **ptrs = malloc(sizeof(struct s_stone *) * (unique_count + 1));
	if (ptrs == NULL)
		return ;
	bzero(ptrs, sizeof(struct s_stone *) * (unique_count + 1));
	copyUnique(ptrs, stone[0]);
	bubbleSortPointers(ptrs, unique_count);
	fixPointers(ptrs);
	stone[0] = ptrs[0];
	free(ptrs);
	return ;
}
