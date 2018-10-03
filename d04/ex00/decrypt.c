#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "header.h"

char 	*getSum0(char *a, char *b, char *out, int index, int *carry)
{
	if (index < 0)
	{
		if (*carry > 0)
			out[index--] = '1';
		return (&out[index+1]);
	}

	int x = a[index] - '0' + b[index] - '0' + *carry;
	if (x % 2 == 1)
		out[index] = '1';
	else
		out[index] = '0';
	if (*carry > 0)
		(*carry)--;
	if (x > 1)
		(*carry) += (x / 2);
	return getSum0(a, b, out, --index, carry);
}

char	*getSum(char *a, char *b)
{
	int carry = 0;
	char *result = malloc(10);
	bzero(result, 10);
	char *ptr = getSum0(a, b, &result[2], 5, &carry);

	int i = 0;				//so that it can be free'd later
	while (ptr[i])
	{
		result[i] = ptr[i];
		i++;
	}
	result[i] = 0;
	return (result);
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
