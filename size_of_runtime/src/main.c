#include <stdio.h>

#define size_of(x)	(size_t)((void *)(&x+1) - (void *)(&x))


int main()
{
	int c, size;
	c = 0x00;
	size = size_of(c);
	printf("%d\n", size);
	char b;
	b = 0x00;
	size = size_of(b);
	printf("%d\n", size);
}
