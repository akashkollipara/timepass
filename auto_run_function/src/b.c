#include <stdio.h>
#include <auto_run.h>

void b()
{
	printf("I am function 'b'...\n");
}

fn_ops_t func_b=
{
	.fn = b
};

FUNCTION_EXPORT(fb,&func_b,0,255);
