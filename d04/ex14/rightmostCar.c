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

int rightmostCar(unsigned int parkingRow)
{
	if (!parkingRow)
		return (-1);

	static int i;
	i ^= i;

	static unsigned int x;
	x ^= x;
	x |= 1;

	while (x)
	{
		if (x & parkingRow)
			return (i);
		increment(&i);
		x <<= 1;
	}
	return (-1);
}
