#include <stdio.h>
#include <stdlib.h>

/* Create a list node with 1 data and 1 next pointer */
struct Node
{
	int data;
	struct Node *next;
	
} typedef node;

/*
 * addEntry: This function adds entry to the list and
 *	     creates addtional nodes.
 *
 * @root - pointer to pointer of list
 * @data - data to be entered in list
 */
void addEntry(node **root, int data)
{
	node *new = (node *)malloc(sizeof(node));
	node *trace;
	new->data = data;
	new->next = NULL;
	if(*root == NULL)
	{
		*root = new;
		return;
	}
	trace = *root;
	while(trace->next != NULL)
		trace = trace->next;
	trace->next = new;
	return;
}

/*
 * deleteEntry - free the memory of the node.
 *
 * @root - pointer to pointer of list
 */
void deleteEntry(node **root)
{
	node *temp = (*root)->next;
	free(*root);
	(*root) = NULL;
	(*root)=temp;
	return;
}

/*
 * freeList - Frees allocated memory of the full list.
 *
 * @root - pointer to pointer of list
 */
void freeList(node **root)
{
	while(*root)
		deleteEntry(root);
	return;
}

/*
 * listSort - Uses bubble sort algorithm to sort a linked list
 *	      in ascending order.
 *
 * @root - pointer to pointer of list
 */
void listSort(node **root)
{
	node *temp, *temp1;
	temp = *root;
	int swap_data;
	while(temp != NULL)
	{
		temp1 = temp->next;
		while(temp1 != NULL)
		{
			if(temp->data > temp1->data)
			{
				swap_data = temp->data;
				temp->data = temp1->data;
				temp1->data = swap_data;
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
}

/*
 * mergeSort - This function uses recurssion to sort the
 *	       linked lists and uses existing nodes of input
 *	       lists to create one merged list.
 * Note	     - This function doesn't maintain integrity of the
 *	       the input lists, but runs faster than below
 *	       algorithm. User need not free memory of input
 *	       lists.
 *
 * @a - Pointer of list
 * @b - Pointer of list
 * @return - pointer of the merged and sorted list
 */
#if 0
node* mergeSort(node *a, node *b)
{
	node *ret = NULL;
	if(a == NULL)
		return b;
	else if(b == NULL)
		return a;

	if(a->data <= b->data)
	{
		ret = a;
		ret->next = mergeSort(a->next, b);
	}
	else
	{
		ret = b;
		ret->next = mergeSort(a, b->next);
	}
	return ret;
}
#endif

/*
 * mergeSort - This function uses recurssion to sort the
 *	       linked lists. It allocates memory for every
 *	       node entry.
 * Note	     - This function is relatively slower than above
 *	       switched off function. User should ensure that
 *	       they free memory of input lists also at the
 *	       exit of the program.
 *
 * @a - Pointer of list
 * @b - Pointer of list
 * @return - pointer of the merged and sorted list
 */
#if 1
node* mergeSort(node *a, node *b)
{
	node *ret = (node *) malloc(sizeof(node));
	if(a == NULL)
	{
		ret->data = b->data;
		ret->next = b->next;
		return ret;
	}
	else if(b == NULL)
	{
		ret->data = a->data;
		ret->next = a->next;
		return ret;
	}

	if(a->data <= b->data)
	{
		ret->data = a->data;
		ret->next = mergeSort(a->next, b);
	}
	else
	{
		ret->data = b->data;
		ret->next = mergeSort(a, b->next);
	}
	return ret;
}
#endif

/*
 * printList - Prints list on console.
 *
 * @root - Pointer of the list
 */
void printList(node *root)
{
	while(root != NULL)
	{
		printf("%d->", root->data);
		root = root->next;
	}
	printf("NULL\n");
	return;
}

int main()
{
	node *r = NULL;
	node *q = NULL;
	node *s = NULL;
	/* Create Linked list r */
	addEntry(&r, 13);
	addEntry(&r, 19);
	addEntry(&r, 31);
	addEntry(&r, 200);
	addEntry(&r, 5);
	addEntry(&r, 3);
	addEntry(&r, 9);
	addEntry(&r, 7);
	addEntry(&r, 11);
	printf("List r: ");
	printList(r);
	/* Create linked list q  */
	addEntry(&q, 12);
	addEntry(&q, 4);
	addEntry(&q, 2001);
	addEntry(&q, 2021);
	addEntry(&q, 2);
	addEntry(&q, 8);
	addEntry(&q, 6);
	addEntry(&q, 10);
	printf("List q: ");
	printList(q);
	/*
	 * Sort linked lists, This creates
	 * Pre-sorted lists
	 */
	listSort(&r);
	listSort(&q);
	/* MergeSort lists */
	s = mergeSort(r, q);

	printf("List s: ");
	printList(s);
	/* Free memory used by 3 lists */
	freeList(&r);
	freeList(&q);
	freeList(&s);

	return 0;
}

