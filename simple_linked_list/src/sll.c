#include <stdio.h>
#include <stdlib.h>
#include <sll.h>

void addNode(node_t **head, int data)
{
	node_t *n = (node_t *) malloc(sizeof(node_t));
	n->data = data;
	n->n = *head;
	*head = n;
	return;
}

void freeList(node_t *head)
{
	node_t *temp, *temp1;
	temp = temp1 = head;
	while(temp1)
	{
		temp1 = temp->n;
		free(temp);
		temp = temp1;
	}
}

void reverseList(node_t **head)
{
	node_t *temp = (node_t *) 0;
	node_t *p = *head;
	while(p)
	{
		p = p->n;
		(*head)->n = temp;
		temp = *head;
		if(p)
			*head = p;
	}
}

void printList(node_t *head)
{
	node_t *temp = head;
	if(!head)
		return;
	while(temp)
	{
		printf("%d->", temp->data);
		temp = temp->n;
	}
	printf("\b\b  \b\b\n");
	return;
}

static void __swap(int *a, int *b)
{
	*b ^= *a;
	*a ^= *b;
	*b ^= *a;
}

static int __stage1sort(node_t **l1, node_t **l2)
{
	int swapped = 0;
	while((*l1)->n != *l2)
	{
		if((*l1)->data > (*l1)->n->data)
		{
			__swap(&((*l1)->data), &((*l1)->n->data));
			swapped = 1;
		}
		*l1 = (*l1)->n;
	}
	*l2 = *l1;
	return swapped;
}

void bubbleSort(node_t *head)
{
	int swapped;
	node_t *p, *lp = (node_t *) 0;

	if(!head)
		return;
	do
	{
		p = head;
		swapped = __stage1sort(&p, &lp);
	} while(swapped);
}
