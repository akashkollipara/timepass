#include <stdio.h>
#include <math.h>
#include <string.h>
#include "lin_mat_ops.h"

unsigned char key[100];
unsigned char txt[100];
unsigned char iky[100];
unsigned char c[100];

int main()
{
	int ord, r_text, size;
	printf("Enter Order of key Matrix: ");
	ord = populate_sqmat(key);
	if(ord < 0)
		return -1;
	//inv_sqmat(key, iky, ord);
	//printf("Inverse ");
	//print_dq_mat(iky, ord);

	printf("Enter Message (lower case): ");
	scanf("%s", txt);
	size = strlen((char *)txt);
	r_text = conv_txt_mat(txt, size, ord);
	mat_mul_mod(txt, key, c, r_text, sqrt(ord));
	conv_mat_txt(c, r_text, sqrt(ord));
	printf("Ciphered Matrix =\n");
	print_mat(c, r_text, sqrt(ord));
	return 0;

}
