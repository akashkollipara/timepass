#include <stdio.h>

int main()
{
	unsigned char a, b;
	a = 0x12;
	b = 0x34;
	b ^= a;
	a ^= b;
	b ^= a;
	printf("a=%x - b=%x\n", (unsigned int)a, (unsigned int)b);
	return 0;
}
