#pragma once

struct DRVLST{
	void (* drvptr)(void);
	unsigned int arg1;
	unsigned int arg2;
	struct DRVLST *prev;
	struct DRVLST *next;
};

struct DRVLST * add_driver(void (* drv)(void));
void driver_init();
struct DRVLST * get_list(void);
