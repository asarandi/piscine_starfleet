#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "header.h"


#define	BYTE_SIZE 6

//The binary representation will always have a length of 6 (000000 to 111111).
//It can represent a positive or negative number (the leftmost bit is the sign bit).

// line 17 tells us that k will always be positive

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
char	*rightShift(char *bin, int k)
{
	char	*shifted = malloc(BYTE_SIZE + 1);
	bzero(shifted, BYTE_SIZE + 1);
	memset(shifted, '0', BYTE_SIZE);

	int i = 0;
	while ((i < BYTE_SIZE) && (i < k))	//filler
	{
		shifted[i] = bin[0];
		i++;
	}

	i = 0;
	while (i < BYTE_SIZE)
	{
		if (i + k < BYTE_SIZE)
			shifted[i + k] = bin[i];
		i++ ;
	}
	bin = strcpy(bin, shifted);
	free(shifted);
	return (bin);
}

char	*leftShift(char *bin, int k)
{
	char	*shifted = malloc(BYTE_SIZE + 1);
	bzero(shifted, BYTE_SIZE + 1);
	memset(shifted, '0', BYTE_SIZE);

	int i = BYTE_SIZE - 1;
	while (i >= 0)
	{
		if (i - k >= 0)
			shifted[i - k] = bin[i];
		i--;
	}
	bin = strcpy(bin, shifted);
	free(shifted);
	return (bin);
}

int		toInt(char *bits)
{
	int	result = 0;
	if (bits[0] == '1')
		to_negative(&bits[1]);
	int i = 1;
	while (bits[i])
	{
		result <<= 1;
		result += bits[i] - '0';
		i++;
	}
	result += bits[0] - '0';
	if (bits[0] == '1')
	{
		to_negative(&bits[1]);
		return (-result);
	}
	return (result);
}
