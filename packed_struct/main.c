#include <stdio.h>

typedef struct
{
	char *name;
	int a;
} __attribute((packed, aligned(1))) test_t;

int main()
{
	test_t hello;
	hello.name = "hello";
	hello.a = 10;
	printf("%ld\n", sizeof(hello));
	return 0;
}
