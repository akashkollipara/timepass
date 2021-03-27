#include <stdio.h>
#include <stdlib.h>
#include <auto_run.h>

extern func_t _table_start, _table_end;

void auto_run()
{
	printf("Auto run ...\n");
	const func_t *fptr;
	int rank;
	for(rank = 0; rank < 256; rank++)
	{
		fptr = &_table_start;
		while(fptr < &_table_end)
		{
			if(rank == fptr->start_rank)
			{
				printf("Rank : %ld\n", fptr->start_rank);
				printf("Running %s: ", fptr->name);
				fptr->ops->fn();
			}
			fptr++;
		}
	}

	for(rank = 255; rank >= 0; rank--)
	{
		fptr = &_table_start;
		while(fptr < &_table_end)
		{
			if(rank == fptr->exit_rank)
			{
				printf("Rank : %ld\n", fptr->exit_rank);
				printf("Running %s: ", fptr->name);
				fptr->ops->fn();
			}
			fptr++;
		}
	}
	return;
}
