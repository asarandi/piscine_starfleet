#include "header.h"
#include <string.h>

// https://en.wikipedia.org/wiki/Binary_search_algorithm

int	searchPrice(struct s_art **arts, int n, char *name)
{
	int	l = 0;
	int	r = n - 1;
	int	m;
	int	cmp;

	while (l <= r)
	{
		m = (l + r) / 2;
		cmp = strcmp(name, arts[m]->name);
		if (cmp > 0)
			l = m + 1;
		else if (cmp < 0)
			r = m - 1;
		else
			return (arts[m]->price);
	}
	return (-1);
}
