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

int occupiedPlaces(unsigned int parkingRow)
{
	static int count;
	count ^= count;

	while (parkingRow)
	{
		if (parkingRow & 1)
			increment(&count);
		parkingRow >>= 1;
	}
	return (count);
}

unsigned int clearBits(unsigned int parkingRow, int n)
{
	static int i;
	i ^= i;
	static unsigned int x;
	x ^= x;

	while (i < n)	//create mask
	{
		x <<= 1;
		x |= 1;
		increment(&i);
	}

	return (parkingRow & (~x));	// AND with negation of mask
}
