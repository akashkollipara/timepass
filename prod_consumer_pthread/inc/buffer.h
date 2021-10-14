/*
 * File		: main.c
 * Author	: Akash Kollipara
 * ID		: 2020HT01001
 * Date		: 05-Nov-2020
 * Project	: SES Assignment 1
 * Description	: Header file for buffer channel functions
 */
#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <stdint.h>

#define MAX_BUFF_SIZE		8

typedef struct buff
{
	char *buffer;
	char *end;
	char *pread;
	char *pwrite;
	int utilization;
	pthread_mutex_t lock;		// For locking the resource
	pthread_cond_t occupy;		// For signaling if the buffer has occupancy, to be used by consumer
	pthread_cond_t vacant;		// For signaling if the buffer has a vacancy, to be used by producer
} buff_t;

int buffer_channel_setup(buff_t *);
int buffer_channel_cleanup(buff_t *);
int buffer_channel_write(buff_t *, char);
int buffer_channel_read(buff_t *, char *);

#endif
