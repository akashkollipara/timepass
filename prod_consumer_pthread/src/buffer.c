/*
 * File		: buffer.c
 * Author	: Akash Kollipara
 * ID		: 2020HT01001
 * Date		: 05-Nov-2020
 * Project	: SES Assignment 1
 * Description	: This file consistsof buffer driver source code.
 *		  It exposes 4 APIs that can be called from the
 *		  top level program to setup buffer channel,
 *		  clean up buffer channel and write-to/read-from
 *		  buffer channel
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <buffer.h>

int buffer_channel_setup(buff_t *b)
{
	/*
	 * Allocate a buffer in heap of size MAX_BUFF_SIZE
	 * Flush the buffer with 0
	 *
	 * Initialise pthread mutex lock
	 * Initialise lock conditions occupy and vacant
	 */
	int error;
	b->buffer = (char *)malloc((sizeof(char) * MAX_BUFF_SIZE));
	if(b->buffer == NULL)
	{
		printf("< x > Failed to allocate memory to buffer!\n");
		printf("< ! > Exiting program!\n");
		return -ENOMEM;
	}
	printf("< / > Allocated %ld Bytes of buffer space!\n", (sizeof(char) * MAX_BUFF_SIZE));
#if DEBUG
	printf("< ! > Buffer starts @ 0x%lx\n", (uintptr_t)b->buffer);
#endif
	memset(b->buffer, 0, sizeof(char) * MAX_BUFF_SIZE);
	b->end = (char *)&b->buffer[MAX_BUFF_SIZE - 1];
#if DEBUG
	printf("< ! > Buffer ends @ 0x%lx\n", (uintptr_t)b->end);
#endif
	b->pread = b->buffer;
	b->pwrite = b->buffer;
	b->utilization = 0;
	error = pthread_mutex_init(&b->lock, NULL);
	error |= pthread_cond_init(&b->occupy, NULL);
	error |= pthread_cond_init(&b->vacant, NULL);
	if(error != 0)
		return error;
	return 0;
}

int buffer_channel_cleanup(buff_t *b)
{
	/*
	 * Free the allocated buffer in heap
	 * Destroy mutex
	 * Destroy lock conditions occupy and vacant
	 */
	int error;
	free(b->buffer);
	error = pthread_mutex_destroy(&b->lock);
	error |= pthread_cond_destroy(&b->occupy);
	error |= pthread_cond_destroy(&b->vacant);
	if(error != 0)
		return error;
	return 0;
}

int buffer_channel_write(buff_t *b, char i)
{
	/*
	 * Acquire lock
	 * Check if the buffer is full
	 * If buffer is full then conditionally release the lock and wait for update
	 * Write to buffer
	 * Increament buffer write pointer
	 * Check for boundary conditions, if write > end, then write=start of buffer
	 * Increament buffer utilization
	 */
	pthread_mutex_lock(&b->lock);

	if(b->utilization >= MAX_BUFF_SIZE)
		printf("< ! > Buffer is full... Awaiting vacancy!\n");

	while(b->utilization >= MAX_BUFF_SIZE)
		pthread_cond_wait(&b->vacant, &b->lock);

#if DEBUG
	printf("< ! > Buffer now @ 0x%lx\n", (uintptr_t)b->pwrite);
#endif
	*(b->pwrite) = i;
#if DEBUG
	printf("< ! > Written to buffer: %u\n", (unsigned int)*(b->pwrite));
#endif
	b->pwrite++;
	b->pwrite = b->pwrite > b->end ? b->buffer : b->pwrite;
	b->utilization++;

	pthread_cond_signal(&b->occupy);

	pthread_mutex_unlock(&b->lock);
	return 0;
}


int buffer_channel_read(buff_t *b, char *i)
{
	/*
	 * Acquire lock
	 * Check if the buffer is emmpty
	 * If buffer is empty then conditionally release the lock and wait for update
	 * Read from buffer
	 * Increament buffer read pointer
	 * Check for boundary conditions, if read > end, then read=start of buffer
	 * Decreament buffer utilization
	 */
	pthread_mutex_lock(&b->lock);

	if(b->utilization <= 0)
		printf("< ! > Buffer is empty... Awaiting occupancy!\n");

	while(b->utilization <= 0)
		pthread_cond_wait(&b->occupy, &b->lock);

#if DEBUG
	printf("< ! > Buffer now @ 0x%lx\n", (uintptr_t)b->pread);
	printf("< ! > Reading from buffer: %u\n", (unsigned int)*(b->pread));
#endif
	*i = *b->pread;
	b->pread++;
	b->pread = b->pread > b->end ? b->buffer : b->pread;
	b->utilization--;

	pthread_cond_signal(&b->vacant);

	pthread_mutex_unlock(&b->lock);
	return 0;
}
