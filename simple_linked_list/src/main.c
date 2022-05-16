#include <stdio.h>
#include <sll.h>

int main()
{
	node_t *root = (node_t *) 0;
	addNode(&root, 3);
	addNode(&root, 5);
	addNode(&root, 6);
	addNode(&root, 4);
	addNode(&root, 1);
	printf("Original List: ");
	printList(root);
	bubbleSort(root);
	printf("Sorted List: ");
	printList(root);
	reverseList(&root);
	printf("Reversed List: ");
	printList(root);
	freeList(root);
	return 0;
}
