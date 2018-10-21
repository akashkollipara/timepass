#include <stdio.h>

void printArray(int *);

void main()
{
	printf("This is insertion sort algo");
	int array[]={23, 25, 1, 12, 15};
        int key = 0, j = 0;
	printf("\nUnsorted Array: ");
	printArray(array);
	for(int i = 1; i < 5; i++)
	{
		key = array[i];
		j = i - 1;
		while(j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
	printf("\nSorted Array: ");
	printArray(array);
	printf("\n");
}

void printArray(int *arr)
{
	int arraySize = sizeof(arr)/sizeof(int);
	for(int i = 0; i < 5; i++)
	{
		printf("%d, ", arr[i]);
	}
}
