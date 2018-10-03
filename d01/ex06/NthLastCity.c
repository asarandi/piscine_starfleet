#include "header.h"
#include <stdio.h>

char	*NthLastCity(struct s_city *city, int n)
{
	struct	s_city	*ptr_right;
	struct	s_city	*ptr_left;

	int i = 0;
	ptr_right = city;
	while (i < n)
	{
		ptr_right = ptr_right->next;
		i++;
	}

	//now ptr_right points to Nth element in list;
	
	ptr_left = city;				//we initialize ptr_left to first element of list
	while (ptr_right->next != NULL)
	{
		ptr_right = ptr_right->next;//we increment both ptr's at the same time
		ptr_left = ptr_left->next;
	}								//now ptr_right is at the end of the list
	return (ptr_left->name);		//ptr_left is N items behind ptr_right
	
}
