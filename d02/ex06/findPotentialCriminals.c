#include "header.h"
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

int getDescription(struct s_info *info)
{
	int	result = 0;
	result += info->piercing	* 1;
	result += info->tattoo		* 10;
	result += info->glasses		* 100;
	result += info->eyeColor	* 1000;
	result += info->hairColor	* 10000;
	result += info->height		* 100000;
	result += info->gender		* 1000000;
	return (result);
}

void countSort(struct s_criminal **criminals, int n, int digit)
{
	int	count[11];
	int	i;
	int	extract;
	
	bzero(count, 11 * sizeof(int));

	i = 0;
	int base = 1;
	while (i < digit)
	{
		base *= 10;
		i++;
	}

	i = 0;
	while (i < n)
	{
		extract = criminals[i]->description;
		extract /= base;
		extract %= 10;

		count[extract] += 1;
		i++;
	}

	struct s_criminal **result = malloc((n + 1) * sizeof(struct s_criminal *));
	bzero(result, (n + 1) * sizeof(struct s_criminal *));
	i = 1;
	while (i < 10)
	{
		count[i] = count[i] + count[i - 1];
		i++;
	}

 	i = n - 1;
	while (i >= 0)
	{
		extract = criminals[i]->description;
		extract /= base;
		extract %= 10;

		result[count[extract] - 1] = criminals[i];
		count[extract]--;
		i--;
	}

	i = 0;
	while (i < n)
	{
		criminals[i] = result[i];
		i++;
	}

	free(result);

	return ;
}

int	countCriminals(struct s_criminal **criminals)
{
	int i = 0;
	while (criminals[i] != NULL)
		i++;
	return (i);
}

void	radix_sort(struct s_criminal **criminals)
{
	int	count = countCriminals(criminals);
	int i = 0;
	while (i < 7)
	{
		countSort(criminals, count, i++);
	}

}


void sortCriminals(struct s_criminal **criminals)
{
//	criminals = NULL;
	radix_sort(criminals);
	return ;
}


int	binary_search(struct s_criminal **criminals, int count, int pattern)
{
	int l = 0;
	int r = count - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (criminals[m]->description < pattern)
			l = m + 1;
		else if (criminals[m]->description > pattern)
			r = m - 1;
		else
			return (m);
	}
	return (-1);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	int description = getDescription(info);
	int count = countCriminals(criminals);
	int index = binary_search(criminals, count, description);
	if (index == -1)
		return (NULL);
	int i = 0;
	while (criminals[index + i]->description == description)
		i++;
	struct s_criminal **result = malloc((i + 1) * sizeof(struct s_criminals *));
	int j = 0;
	while (j < i)
	{
		result[j] = criminals[index + j];
		j++;
	}
	result[j] = NULL;

	
	return (result);
}


