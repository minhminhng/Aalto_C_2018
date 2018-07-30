#include <stdio.h>

/*
 * Implement function sixBits which returns only least significant six bits
 * of the input value v.
 */
unsigned char sixBits(unsigned char v)
{
	return (v & 0x3F);
	// return (v & 63);
	// return (v & 0b00111111)
}

int main(void)
{
    printf("%02x\n", sixBits(0xDF));
    printf("%02x\n", sixBits(0x8D));
    printf("%02x\n", sixBits(0x28));
}
