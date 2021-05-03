#include <stdio.h>
#include "conv.h"

int __conv(int *a, int size_a, int *b, int size_b, int *c, int size_c)
{
	int rstart, rend, r;
	if(size_c < (size_a + size_b - 1))
		return -1;

	for(int ci = 0; ci < size_c; ci++)
	{
		rstart = (ci >= size_b - 1) ? ci - (size_b - 1) : 0;
		rend = (ci < size_a - 1) ? ci : size_a - 1;

		for(r = rstart; r <= rend; r++)
			c[ci] += a[r] * b[ci-r];
	}
	return 0;
}
