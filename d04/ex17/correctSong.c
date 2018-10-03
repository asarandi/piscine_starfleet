#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>

void	correctSong(struct s_bit *bit, int len, int row, int col, int dist)
{
	int	**res = malloc((bit->n + 1) * sizeof(int *));
	bzero(res, (bit->n + 1) * sizeof(int *));
////////unpack
	int i = 0;
	while (i < bit->n)
	{
		res[i] = malloc(len * sizeof(int));
		bzero(res[i], len * sizeof(int));

		int j = 0;
		while (j < len)
		{
			res[i][j] = bit->arr[i] & 1;
			bit->arr[i] >>= 1;
			j++;
		}
		i++;
	}
	res[i] = NULL;
////////fix
	i = 0;
	while (i < dist)
	{
		res[row][col] = 1;
		col++;
		if (col >= len)
		{
			row++;
			col=0;
		}
		if (res[row] == NULL)
			break ;
		i++;
	}
////////pack
	i = 0;
	row = 0;
	col = 0;
	int	myint;
	int tmp;
	int index;
	int shift;

	while (i < bit->n)
	{
		col = 0;
		myint = 0;
		index = 0;
		shift = 0;
		while (index < len)
		{
			tmp = res[i][col] << shift;
			myint += tmp;
			col++;
			shift++;
			index++;
		}
		bit->arr[i] = myint;
		i++;
	}

	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);

}
