#include "header.h"
#include <stdio.h>


int	binarySearch(int *a, int l, int r, int value)
{
	if (l > r)
		return (-1);
	int	mid = (l + r) / 2;
	if (a[mid] == value)
		return (mid);
	if (a[l] <= a[mid])
	{
		if ((value >= a[l]) && (value <= a[mid]))
			return (binarySearch(a, l, mid - 1, value));
		return (binarySearch(a, mid + 1, r, value));
	}
	if ((value >= a[mid]) && (value <= a[r]))
		return (binarySearch(a, mid + 1, r, value));
	return (binarySearch(a, l, mid - 1, value));
}

int	searchShifted(int *rocks, int length, int value)
{

//	for (int i = 0; i < length; i++) {
//		printf("index = %d, value = %d\n", i, rocks[i]);
//	}
	
	int	result;
	result = binarySearch(rocks, 0, length - 1, value);
	while ((result > 0) && (rocks[result] == rocks[result-1]))
		result--;
	if ((result == 0) && (rocks[result] == rocks[length-1]))
		result = length-1;
	while ((result > 0) && (rocks[result] == rocks[result-1]))
		result--;
	return (result);
}
