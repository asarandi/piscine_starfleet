#include "header.h"

unsigned int	clearPlace(unsigned int parkingRow, int pos)
{
	unsigned int x = 1 << pos;	//shift 1 to the left, if pos = 3,	0000100
	x = ~x;						//invert							1111011
	return (parkingRow & x);	//logical and to clear everything but `pos`; keep all bits except 3
}
