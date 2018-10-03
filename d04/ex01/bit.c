#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "header.h"

void	to_negative(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == '0')
			s[i]++;
		else if (s[i] == '1')
			s[i]--;
		i++;
	}
}

char	*getAnd(char *a, char *b)
{
	if (*a == '~')
		to_negative(a++);
	if (*b == '~')
		to_negative(b++);
	int i = 0;
	while (a[i])
	{
		a[i] = a[i] & b[i];
		i++;
	}
	return (a);
}

char	*getOr(char *a, char *b)
{
	if (*a == '~')
		to_negative(a++);
	if (*b == '~')
		to_negative(b++);
	int i = 0;
	while (a[i])
	{
		a[i] = a[i] | b[i];
		i++;
	}
	return (a);
}

int		toInt(char *bits)
{
	int	result = 0;
	int i = 0;
	while (bits[i])
	{
		result <<= 1;
		result += bits[i] - '0';
		i++;
	}
	return (result);
}
