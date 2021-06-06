#include <stdio.h>

#define size_of(x, size)	void *temp##x;		\
				temp##x = (x);		\
				(size) = (unsigned)((size_t)(++(x)) - (size_t)temp##x);

int main()
{
	int *c, size;
	c = 0x00;
	size_of(c, size);
	printf("%d\n", size);
	char *b;
	b = 0x00;
	size_of(b, size);
	printf("%d\n", size);
}
