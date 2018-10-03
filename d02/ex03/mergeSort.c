#include "header.h"
#include <stdlib.h>
#include <string.h>

struct s_player	**merge(struct s_player **left, int l, struct s_player **right, int r)
{
	int i = 0;
	int j = 0;
	int k = 0;
	struct s_player	**merged;

	merged = malloc(sizeof(struct s_player *) * (l + r));
	while ((i < l) && (j < r))
	{
		if (left[i]->score > right[j]->score)		//first compare by score, sort descending
			merged[k++] = left[i++];
		else if (left[i]->score < right[j]->score)
			merged[k++] = right[j++];
		else									//if scores are equal, compare by time string, sort ascending
		{
			if (strcmp(left[i]->timeStamp, right[j]->timeStamp) < 0)	
				merged[k++] = left[i++];
			else
				merged[k++] = right[j++];
		}
	}
	while (i < l)
		merged[k++] = left[i++];
	while (j < r)
		merged[k++] = right[j++];
	i = 0;
	while (i < l + r)
	{
		left[i] = merged[i];
		i++;
	}
	free(merged);
	return (left);
}

struct s_player	**split(struct s_player **players, int count)
{
	if (count < 2)
		return (players);

	int l = count / 2;
	int r = count - l;

	split(&players[0], l);
	split(&players[l], r);
	players = merge(&players[0], l, &players[l], r);
	return (players);
}


int	playersCount(struct s_player **players)
{
	int	i = 0;
	while (players[i] != NULL)
		i++;
	return (i);
}

struct	s_player **mergeSort(struct s_player **players)
{
	int	count = playersCount(players);
	players = split(players, count);
	return (players);
}
