#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool get_bit_with_index(void *mem, uint32_t index)
{
	uint32_t offset = index / 8;
	uint32_t shift = index % 8;

	char var = ((char *)mem)[offset];
	return (var & (1 << shift)) ? true : false;
}

int find_parttern_index_from_stream(void *stream, uint32_t bssize, void *patt, uint32_t bpsize)
{
	uint32_t i, j, match_count = 0;

	if(bssize < bpsize)
		return -2;

	for(i = 0; i < bssize; i++)
	{
		for(j = 0; j < bpsize; j++)
		{
			if(bssize <= (i + j))
				return -1;
			if(get_bit_with_index(stream, (i + j)) ^
				get_bit_with_index(patt, j))
			{
				match_count = 0;
				break;
			}
			else
				match_count += 1;
		}
		if(match_count == bpsize)
			return i;
	}
	return -1;
}

int main()
{
#pragma pack(1)
	char stream[] = {0, 0x21, 0x13, 0x30, 0x22};
	char patt[] = {0x46};
#pragma pack()
	int s = sizeof(stream) * 8;
	int p = sizeof(patt) * 8;
	printf("NB(stream) = %d, NB(patt) = %d\n", s, p);
	int v = find_parttern_index_from_stream(stream, s, patt, p);
	printf("Match at %d\n", v);
	return 0;
}
