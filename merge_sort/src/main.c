#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
	
} typedef node;

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

void deleteEntry(node **root)
{
	node *temp = (*root)->next;
	free(*root);
	(*root) = NULL;
	(*root)=temp;
	return;
}

void freeList(node **root)
{
	while(*root)
		deleteEntry(root);
	return;
}

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

node* mergeSort1(node *a, node *b)
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
		ret->next = mergeSort1(a->next, b);
	}
	else
	{
		ret->data = b->data;
		ret->next = mergeSort1(a, b->next);
	}
	return ret;
}

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
	addEntry(&r, 13);
	addEntry(&r, 5);
	addEntry(&r, 3);
	addEntry(&r, 9);
	addEntry(&r, 7);
	addEntry(&r, 11);
	printf("List r: ");
	printList(r);
	addEntry(&q, 12);
	addEntry(&q, 4);
	addEntry(&q, 2);
	addEntry(&q, 8);
	addEntry(&q, 6);
	addEntry(&q, 10);
	printf("List q: ");
	printList(q);
	listSort(&r);
	listSort(&q);
	s = mergeSort1(r, q);
	printf("List s: ");
	printList(s);
	freeList(&r);
	freeList(&q);
	freeList(&s);
	return 0;
}

