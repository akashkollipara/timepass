#include "malloc.h"

uint8_t arena[512];	// 512 Bytes of heap arena
chunk_t *freeList;

static void split(chunk_t *fit_slot, size_t size)
{
	chunk_t *new = (void *)((void *) fit_slot + size + sizeof(chunk_t));
	new->size = fit_slot->size - size - sizeof(chunk_t);
	new->free = 1;
	new->next = fit_slot->next;
	fit_slot->size = size;
	fit_slot->free = 0;
	fit_slot->next = new;
	return;
}

static void merge()
{
	chunk_t *cur;
	cur = freeList;
	while(cur->next != NULL)
	{
		if(cur->free && cur->next->free)
		{
			cur->size += cur->next->size + sizeof(chunk_t);
			cur->next = cur->next->next;
		}
		cur = cur->next;
	}
}

void init_heap()
{
	freeList = (void *)arena;
	freeList->size = 512-sizeof(chunk_t);
	freeList->free = 1;
	freeList->next = NULL;
}

void *imalloc(size_t n_bytes)
{
	chunk_t *cur;

	if(!freeList->size)
		return NULL;
	cur = freeList;
	while(cur->size < n_bytes || (!cur->free && cur->next))
		cur = cur->next;
	if(cur->size == n_bytes)
		cur->free = 0;
	else if(cur->size > (n_bytes + sizeof(chunk_t)))
		split(cur, n_bytes);
	else
		return NULL;
	return (void *)(++cur);
}

void ifree(void *ptr)
{
	if((void *)arena <= ptr && ptr <= ((void*)arena + sizeof(arena)))
	{
		chunk_t *cur = ptr;
		cur->free = 1;
		merge();
	}
	return;
}
