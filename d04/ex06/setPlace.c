#include "header.h"

unsigned int setPlace(unsigned int parkingRow, int pos)
{
	unsigned int x = 1 << pos;
	return (parkingRow | x);
}
