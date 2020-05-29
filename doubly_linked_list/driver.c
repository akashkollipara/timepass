#include <stdio.h>
#include <stdlib.h>
#include <driver.h>

static struct DRVLST *head = NULL, *tail = NULL;

struct DRVLST * add_driver(void (* drv)(void))
{
   struct DRVLST *element;
	
        element = (struct DRVLST *)malloc(sizeof(struct DRVLST));
        element->prev = tail;
        element->next = NULL;
        if (tail) tail->next = element;
        tail = element;
        element->drvptr = drv;

   return(element);
}

extern void a(void);
extern void b(void);

void driver_init()
{
	printf("Driver init ...\n");
	head = add_driver(a);
	add_driver(b);
	return;
}

struct DRVLST * get_list( void )
{
	return(head);
}
