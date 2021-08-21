#pragma once

#include <stdint.h>
#include <stddef.h>

typedef struct chunk
{
	size_t size;
	int free;
	struct chunk *next;
} chunk_t;

void init_heap();
void *imalloc(size_t n_bytes);	// implemented malloc
void ifree(void *ptr);	// implemented free
