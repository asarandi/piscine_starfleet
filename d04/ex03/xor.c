#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "header.h"

char	*getXor(char *a, char *b)
{
	int i = 0;
	while (a[i])
	{
		a[i] = (a[i] ^ b[i]) + '0';
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
