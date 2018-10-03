#include <string.h>
#include "header.h"

int	searchPrice(struct s_art **arts, char *name)
{
	int	i = 0;

	while (arts[i] != NULL)
	{
		if (strcmp(arts[i]->name, name) == 0)
		{
			return ((int)arts[i]->price);
		}
		i++;
	}
	return (-1);
}
