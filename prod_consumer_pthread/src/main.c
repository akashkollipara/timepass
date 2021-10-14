/*
 * File		: main.c
 * Author	: Akash Kollipara
 * ID		: 2020HT01001
 * Date		: 05-Nov-2020
 * Project	: SES Assignment 1
 * Description	: This is the main file of the SES assignment project
 *		  This consists of producer and consumer threads that
 *		  call the buffer driver for write and read operation
 *		  respectively.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <buffer.h>

#define N_ITERS		20

// Buffer structure used by this program
buff_t mybuff;

void *producer(void *arg __attribute__((unused)))
{
	/*
	 * Seed pseudo random number
	 * Loop to store 20 random numbers
	 * Sleep
	 * Get 8b random value
	 * Store the value to buffer
	 * Clean and exit gracefully
	 */

	int i, sample;
	time_t t;
	srand((unsigned)time(&t));
	for(i = 0; i < N_ITERS; i++)
	{
		/*
		 * Sleep at start so that consumer waits for
		 * buffer to be populated
		 */
		sleep(1);
		sample = rand() % 256;
		printf("[Producer %ld]: Storing value %d\n", pthread_self(), sample);
		fflush(stdout);
		if(buffer_channel_write(&mybuff, (char)sample) == -ENOMEM)
			break;
	}
	pthread_exit(NULL);
}

void *consumer(void *arg __attribute__((unused)))
{
	/*
	 * Loop to fetch 20 data elements
	 * Fetch the value from buffer
	 * Sleep
	 * clean and exit gracefully
	 */
	int sample;
	for(int i = 0; i < N_ITERS; i++)
	{
		if(buffer_channel_read(&mybuff, (char *)&sample) == -ENOMEM)
			break;
		printf("[Consumer %ld]: Fetching value %d\n", pthread_self(), sample);
		fflush(stdout);
		/*
		 * Sleep for more than producation rate so that
		 * producer will wait after the buffer is full
		 */
		sleep(2);
	}
	pthread_exit(NULL);
}

int main()
{
	/*
	 * Initialise the buffer channel
	 * Initialise the attribute
	 * Assign attribute as JOINABLE
	 * Create producer pthread
	 * Create consumer pthread
	 * Wait for consumer to complete execution
	 * wait for producer to complete execution
	 * Clean up attributes
	 * Clean up buffer channel
	 */
	int error;
	pthread_t p_pid, c_pid;
	pthread_attr_t thread_attr;

	error = buffer_channel_setup(&mybuff);
	if(error)
		goto exit;
	error = pthread_attr_init(&thread_attr);
	if(error)
		goto exit;
	error = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_JOINABLE);
	if(error)
		goto exit;
	error = pthread_create(&p_pid, &thread_attr, &producer, NULL);
	if(error)
		goto exit;
	error = pthread_create(&c_pid, &thread_attr, &consumer, NULL);
	if(error)
		goto pexit1;
	pthread_join(c_pid, NULL);
pexit1:
	pthread_join(p_pid, NULL);
exit:
	pthread_attr_destroy(&thread_attr);
	error = buffer_channel_cleanup(&mybuff);
	if(error != 0)
		return error;
	return 0;
}
