#pragma once

typedef struct node
{
	struct node *n;
	int data;
} node_t;

void addNode(node_t **, int);
void freeList(node_t *);
void printList(node_t *);
void bubbleSort(node_t *);
