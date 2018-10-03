#include "header.h"


void increment(int *x)
{
	static int m;
	m ^= m;	//set m to zero
	m |= 1; //set m to one
	while (*x & m) //loop to flip all bits
	{
		*x ^= m;
		m <<= 1;
	}
	*x ^= m; //set rightmost zero bit to 1
}

int longestSequence(unsigned int parkingRow)
{
	if (!parkingRow)
		return (0);

	static int i;
	i ^= i;

	while (parkingRow)
	{
		increment(&i);
		parkingRow &= (parkingRow << 1);
	}
	return (i);
}
