#pragma once

typedef struct fn_ops
{
	void (*fn)(void);
} fn_ops_t;

typedef struct function
{
	char *name;
	fn_ops_t *ops;
	unsigned long start_rank;
	unsigned long exit_rank;
} func_t;

#define FUNCTION_EXPORT(_name,_ops,_srank,_erank)			\
	const func_t _name __attribute__((section(".func_table")))=	\
	{								\
		.name = #_name,						\
		.ops = _ops,						\
		.start_rank = _srank,					\
		.exit_rank = _erank,					\
	};

void auto_run();
