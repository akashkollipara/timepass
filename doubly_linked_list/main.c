#include <stdio.h>
#include <driver.h>

int main()
{
	struct DRVLST * fncpt;
	driver_init();
	fncpt = get_list();
	while(fncpt != NULL) {
		fncpt -> drvptr();
		fncpt = fncpt->next;
	}
	return 0;
}
