#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"

int main()
{
	char *buff;
	int size;
	init_heap();
	printf("Enter size in bytes: ");
	scanf("%d", &size);
	buff = imalloc(size);
	if(!buff)
		return -1;
	printf("Enter text of size - %d: ", size);
	scanf("%s", buff);
	printf("You Entered: %s\n", buff);
	ifree(buff);
	return 0;
}
