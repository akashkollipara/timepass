#include <stdio.h>
#include <stdint.h>
#include <auto_run.h>

int main()
{
	auto_run();
	printf("\n\n%ld\n", sizeof(size_t));
	printf("\n\n%ld\n", sizeof(uintptr_t));
	printf("\n\n%ld\n", sizeof(void *));
	printf("\n\n%ld\n", sizeof(unsigned long));
	printf("\n\n%ld\n", sizeof(long long));
	return 0;
}
