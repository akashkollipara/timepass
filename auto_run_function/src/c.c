#include <stdio.h>
#include <auto_run.h>

void c()
{
	printf("I am function 'c'...\n");
}

fn_ops_t func_c=
{
	.fn = c
};

FUNCTION_EXPORT(fc,&func_c,2,4);
