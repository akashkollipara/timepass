#include <stdio.h>
#include <auto_run.h>

void a()
{
	printf("I am function 'a'...\n");
}

fn_ops_t func_a=
{
	.fn = a
};

FUNCTION_EXPORT(fa,&func_a,0,0);
