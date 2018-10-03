#include "header.h"
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

void countSort(unsigned char *utensils, int n)
{
	int	*count;
	unsigned char *result;
	int i;
	
	count = malloc(n * sizeof(int));
	bzero(count, n * sizeof(int));

	i = 0;
	while (i < n)
	{
		count[utensils[i]] += 1;
		i++;
	}

	result = malloc(n + 1);
	bzero(result, n + 1);
	i = 1;
	while (i < 256)
	{
		count[i] = count[i] + count[i - 1];
		i++;
	}

 	i = 0;
	while (i < n)
	{
		result[count[utensils[i]] - 1] = utensils[i];
		count[utensils[i]]--;
		i++;
	}

	i = 0;
	while (i < n)
	{
		utensils[i] = result[i];
		i++;
	}

	free(result);
	free(count);

	return ;
}
