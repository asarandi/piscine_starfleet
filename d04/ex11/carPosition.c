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

/*
** wikipedia: Exponential function: raises a fixed number to a variable power.
** https://en.wikipedia.org/wiki/List_of_mathematical_functions
** https://en.wikipedia.org/wiki/Exponentiation#Power_functions
*/

void power_of_two(unsigned int *x)
{
	*x <<= 1;
}

int carPosition(unsigned int parkingRow)
{
	if (occupiedPlaces(parkingRow) & 1)
	{
		static int res;
		res ^= res;
		static unsigned int x;
		x ^= x;
		x |= 1;
		while (1)
		{
			if (parkingRow & x)
				return (res);
			power_of_two(&x);
			increment(&res);
		}
	}
	return (-1);
}
