#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int		**pianoDecompress(struct s_bit *bit, int len)
{
	int	**res = malloc((bit->n + 1) * sizeof(int *));
	bzero(res, (bit->n + 1) * sizeof(int *));
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
	return (res);
}
