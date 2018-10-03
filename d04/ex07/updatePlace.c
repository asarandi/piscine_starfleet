#include "header.h"

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
	// if value == 0 .. clear bit, else set bit
	unsigned int x = 1 << pos;
	if (value == 0)
		return (parkingRow & (~x));
	return (parkingRow | x);
}
