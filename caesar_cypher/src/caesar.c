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

int main()
{
	char ip_string[26], op_string[26];
	int index = 0, size, ed, key;
	printf("Enter Caesay key: ");
	size = scanf("%d", &key);

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

	while(index < size)
	{
		switch(ed)
		{
			case 1:
				caesar_encrypt(key, ip_string[index], &op_string[index]);
				break;
			case 2:
				caesar_decrypt(key, ip_string[index], &op_string[index]);
				break;
		}
		index++;
	}
	op_string[index] = '\0';

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
