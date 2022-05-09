#include <sll.h>

int main()
{
	node_t *root = (node_t *) 0;
	addNode(&root, 3);
	addNode(&root, 5);
	addNode(&root, 6);
	addNode(&root, 4);
	printList(root);
	bubbleSort(root);
	printList(root);
	freeList(root);
	return 0;
}
