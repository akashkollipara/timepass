#include <stdio.h>
#include <auto_run.h>

void hello_world()
{
	printf("Hello World!\n");
}

fn_ops_t func_hello_world=
{
	.fn = hello_world
};

FUNCTION_EXPORT(fhello_world,&func_hello_world,6,9);
