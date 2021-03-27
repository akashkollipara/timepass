#include <stdio.h>
#include <auto_run.h>

void d()
{
	printf("I am function 'd'...\n");
}

fn_ops_t func_d=
{
	.fn = d
};

FUNCTION_EXPORT(fd,&func_d,5,1);
