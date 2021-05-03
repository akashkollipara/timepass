#include <stdio.h>
#include "conv.h"

#define print_arr(x)	__print_arr(x, sizeof(x)/sizeof(x[1]))

void __print_arr(int *arr, int size)
{
	for(int i = 0; i < size; i++)
		printf("%d - ", arr[i]);
	printf("eoa\n");
}

int main()
{
	int arr[] = {1, 1, 1};
	int brr[] = {1, 1, 1};
	int crr[5] = {0, 0, 0, 0, 0};
	printf("arr: ");
	print_arr(arr);
	printf("brr: ");
	print_arr(brr);
	conv(arr, brr, crr);
	printf("crr: ");
	print_arr(crr);
	return 0;
}
