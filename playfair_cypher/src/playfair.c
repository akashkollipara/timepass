#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char playfair_matrix[25];

static int populate_matrix(char ip)
{
	static unsigned int x = 0;
	for(int i = 0; i < x; i++)
	{
		if(playfair_matrix[i] == ip)
			return 1;
	}
	playfair_matrix[x] = ip;
	x = x < 24 ? (x + 1) : 0;
	return 0;
}

void disp_playfair_matrix()
{
	int i = 0;
	printf("Playfair Matrix:\n ");
	for(i = 0; i < 5; i++)
		printf("----");
	printf("\b \n");
	for(i = 0; i < 25; i++)
	{
		if((i%5) == 0 && i != 0)
			printf("|\n");
		printf("| %c ", playfair_matrix[i]);
	}
	printf("|\n ");
	for(i = 0; i < 5; i++)
		printf("----");
	printf("\b \n");
}

static void generate_matrix(char *ip)
{
	char a, i;
	printf("\nGenerating Playfair Matrix: [");
	while(*ip != '\0')
	{
		populate_matrix(*ip);
		ip++;
	}

	for(i = 'a'; i <= 'z'; i++)
	{
		a = (i == 'j') ? 'i' : i;
		populate_matrix(a);
		printf("=");
	}
	printf("]\n\n");
	disp_playfair_matrix();
}

static void split_digrams(char *ip, char *op, int size, int *index)
{
	int local_index = *index;
	if(local_index > 2)
		if(ip[local_index-1] == ip[local_index-2])
		{
			local_index--;
			(*index)--;
		}

	op[0] = ip[local_index];

	if(size > local_index+1)
		op[1] = ip[local_index] == ip[local_index+1] ? 'x' : ip[local_index+1];
	else
		op[1] = 'x';
}

void get_xy_from_char(char ip, int *xy)
{
	int i;
	ip = ip == 'j' ? 'i' : ip;
	for(i = 0; i < 25; i++)
		if(playfair_matrix[i] == ip)
			break;
	xy[0] = i/5;
	xy[1] = i%5;
}

void get_char_from_xy(int *xy, char *op)
{
	*op = playfair_matrix[((xy[0]*5)+xy[1])];
}

void playfair_encrypt(char *dg, char *op)
{
	int xy1[2];
	int xy2[2];
	int temp;
	get_xy_from_char(dg[0], xy1);
	get_xy_from_char(dg[1], xy2);

	if(xy1[0] == xy2[0] && xy1[1] != xy2[1])
	{
		xy1[1]++;
		xy1[1] = xy1[1] > 4 ? 0 : xy1[1];
		xy2[1]++;
		xy2[1] = xy2[1] > 4 ? 0 : xy2[1];
	}
	else if(xy1[0] != xy2[0] && xy1[1] == xy2[1])
	{
		xy1[0]++;
		xy1[0] = xy1[0] > 4 ? 0 : xy1[0];
		xy2[0]++;
		xy2[0] = xy2[0] > 4 ? 0 : xy2[0];
	}
	else 
	{
		temp = xy1[1];
		xy1[1] = xy2[1];
		xy2[1] = temp;
	}

	get_char_from_xy(xy1, &op[0]);
	get_char_from_xy(xy2, &op[1]);
}

void playfair_decrypt(char *dg, char *op)
{
	int xy1[2];
	int xy2[2];
	int temp;
	get_xy_from_char(dg[0], xy1);
	get_xy_from_char(dg[1], xy2);

	if(xy1[0] == xy2[0] && xy1[1] != xy2[1])
	{
		xy1[1]--;
		xy1[1] = xy1[1] < 0 ? 4 : xy1[1];
		xy2[1]--;
		xy2[1] = xy2[1] < 0 ? 4 : xy2[1];
	}
	else if(xy1[0] != xy2[0] && xy1[1] == xy2[1])
	{
		xy1[0]--;
		xy1[0] = xy1[0] < 0 ? 4 : xy1[0];
		xy2[0]--;
		xy2[0] = xy2[0] < 0 ? 4 : xy2[0];
	}
	else 
	{
		temp = xy1[1];
		xy1[1] = xy2[1];
		xy2[1] = temp;
	}

	get_char_from_xy(xy1, &op[0]);
	get_char_from_xy(xy2, &op[1]);
}

int main()
{
	char ip_string[26], op_string[26], temp_op[2];
	int index = 0, cntr, size, ed;
	printf("Enter playfair key: ");
	size = scanf("%s", ip_string);
	generate_matrix(ip_string);

	printf("Enter:\n\t1. Encrypt\n\t2. Decrypt\n> ");
	size = scanf("%d", &ed);
	if(ed < 1 || ed > 2)
	{
		printf("Error!\n");
		return -1;
	}

	printf("Enter data: ");
	size = scanf("%s", ip_string);

	size = strlen(ip_string);
	cntr = 0;

	while(index < size)
	{
		split_digrams(ip_string, temp_op, size, &index);
		index += 2;
		switch(ed)
		{
			case 1:
				playfair_encrypt(temp_op, temp_op);
				break;
			case 2:
				playfair_decrypt(temp_op, temp_op);
				break;
		}
		op_string[cntr] = temp_op[0];
		op_string[++cntr] = temp_op[1];
		cntr++;
	}
	op_string[cntr] = '\0';

	switch(ed)
	{
		case 1:
			printf("Encrypted Data = %s\n", op_string);
			break;
		case 2:
			printf("Decrypted Data = %s\n", op_string);
			break;
	}
	return 0;
}
