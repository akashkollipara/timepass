#include <stdio.h>

void print_arr(int *arr, int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void rev_arr_from(int *arr, int size, int index)
{
	int temp, i = 0;
	if(size <= index)
	{
		printf("Error! Index >= size ...\n");
		return;
	}

	while(i < index)
	{
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
		i++; index--;
	}
}

int find_largest_index(int *arr, int size)
{
	int temp = 0, i, ret;
	for(i = 0; i <= size; i++)
		if(temp < arr[i])
		{
			temp = arr[i];
			ret = i;
		}
	return ret;
}

void sort_by_rev(int *arr, int size)
{
	int index = size-1, li;
	while(index)
	{
		li = find_largest_index(arr, index);
		rev_arr_from(arr, size, li);
		rev_arr_from(arr, size, index--);
	}
}


int main()
{
	int arr[] = {7, 3, 6, 13, 8, 5, 9, 10, 4, 1, 2};
	printf("Unsorted Array: ");
	print_arr(arr, sizeof(arr)/4);
	sort_by_rev(arr, sizeof(arr)/4);
	printf("Sorted Array: ");
	print_arr(arr, sizeof(arr)/4);
	return 0;
}
