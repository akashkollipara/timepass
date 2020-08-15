#include <stdio.h>
#include <stdint.h>

#pragma pack(1)
typedef struct port
{
	uint8_t b0 : 1;
	uint8_t b1 : 1;
	uint8_t b2 : 1;
	uint8_t b3 : 1;
	uint8_t b4 : 1;
	uint8_t b5 : 1;
	uint8_t b6 : 1;
	uint8_t b7 : 1;
} port_t;

int main()
{
	port_t *port_b;
	port_t portb;
	portb.b0 = 1;
	portb.b1 = 0;

	printf("sizeof of port_t: %ld\n", sizeof(port_t));
	printf("&portb: %p\n", &portb);
	printf("portb.b0: %x\n", portb.b0);
	printf("portb.b1: %x\n", portb.b1);
	
	port_b = &portb;
	printf("&port_b: %p\n", port_b);
	printf("port_b->b0: %x\n", port_b->b0);
	printf("port_b->b1: %x\n", port_b->b1);
	
	port_b = (port_t *) 0x20;
	printf("&port_b: %p\n", port_b);
	printf("port_b->b0: %x\n", port_b->b0);
	printf("port_b->b1: %x\n", port_b->b1);
	return 0;
}
