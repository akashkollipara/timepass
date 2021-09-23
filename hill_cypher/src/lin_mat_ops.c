#include <stdio.h>
#include <math.h>

int mod(int a, int b)
{
	int ret = a % b;
	ret = (ret < 0) ? b + ret : ret;
	return ret;
}

int populate_sqmat(unsigned char *mat)
{
	int ord;
	scanf("%d", &ord);
	if(ord/sqrt(ord) != sqrt(ord))
		return -1;
	for(int i = 0; i < ord; i++)
	{
		printf("Enter Element %d: ", i);
		scanf("%d", (int *)&mat[i]);
	}
	return ord;
}

void print_sqmat(unsigned char *mat, int ord)
{
	int r, c;
	r = sqrt(ord);
	c = ord/r;
	printf("Matrix = \n");
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
			printf("%d\t", mat[i * c + j]);
		printf("\n");
	}
	return;
}

int conv_txt_mat(unsigned char *mat, int size, int ord)
{
	int r_text;
	int rem = size % (int)sqrt(ord);
	size = (rem != 0) ? size + (sqrt(ord) - rem) : size;
	r_text = size / sqrt(ord);
	for(int i = 0; i < size; i++)
	{
		if(mat[i] == '\0')
			mat[i] = 'x';
		mat[i] -= 'a';
	}
	return r_text;
}

void mat_mul_mod(unsigned char *a, unsigned char *b, unsigned char *c, int ro, int co)
{
	int tot = 0;
	for (int i = 0; i < ro; i++)
	{
		for (int j = 0; j < co; j++)
		{
			for (int k = 0; k < co; k++)
			{
				tot = tot + (unsigned int)a[i + (ro * k)] * (unsigned int)b[(k * co) + j];
			}
			c[i + (ro * j)] = mod(tot, 26);
			tot = 0;
		}
	}
}

void print_mat(unsigned char *mat, int r, int c)
{
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
			printf("%d\t", (int)mat[i + (j * r)]);
		printf("\n");
	}
}

void conv_mat_txt(unsigned char *a, int r, int c)
{
	for(int i = 0; i < (r*c); i++)
	{
		printf("Debug Text Elements: %c\n", (a[i] + 'a'));
	}
}
