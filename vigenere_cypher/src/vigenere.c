#include <stdio.h>
#include <string.h>

int mod(int a, int b)
{
	int ret = a % b;
	ret = (ret < 0) ? b + ret : ret;
	return ret;
}

void caesar_encrypt(int key, const char i, char *o)
{
	int p = (int)(i - 'a');
	*o = (char)mod((p + key), 26) + 'a';
}

void caesar_decrypt(int key, const char i, char *o)
{
	int p = (int)(i - 'a');
	*o = (char)mod((p - key), 26) + 'a';
}

void vigenere_encrypt(char *key, char *ip, char *op)
{
	int index, size = strlen(key);
	while(*ip != '\0')
	{
		caesar_encrypt((int)(key[index]-'a'), *ip, op);
		ip++;
		op++;
		index = (index < size-1) ? (index+1) : 0;
	}
	*op = *ip;
}

void vigenere_decrypt(char *key, char *ip, char *op)
{
	int index, size = strlen(key);
	while(*ip != '\0')
	{
		caesar_decrypt((int)(key[index]-'a'), *ip, op);
		ip++;
		op++;
		index = (index < size-1) ? (index+1) : 0;
	}
	*op = *ip;
}

int main()
{
	char ip_string[100], op_string[100], key[100];
	int size, ed;
	printf("Enter Vigenere key: ");
	size = scanf("%s", key);

	printf("Enter:\n\t1. Encrypt\n\t2. Decrypt\n> ");
	size = scanf("%d", &ed);
	if(ed < 1 || ed > 2)
	{
		printf("Error!\n");
		return -1;
	}

	printf("Enter data: ");
	size = scanf("%s", ip_string);
	(void) size;

	switch(ed)
	{
		case 1:
			vigenere_encrypt(key, ip_string, op_string);
			break;
		case 2:
			vigenere_decrypt(key, ip_string, op_string);
			break;
	}

	switch(ed)
	{
		case 1:
			printf("Encrypted Data = %s\n", op_string);
			break;
		case 2:
			printf("Decrypted Data = %s\n", op_string);
			break;
	}
}
