#include <stdio.h>

void printBits(unsigned char value)
{
	for (int i = 7; i >= 0; i--) {
	// (1 << i) generates value where only i'th bit is set
	// value & (1 << i)) is non-zero only if i'th bit is set in value
	if (value & (1 << i))
    	printf("1");
	else
		printf("0");
	}
}

void printBits2(unsigned char value)
{
	for (int i = 0; i <= 7; i++) {
	// (1 << i) generates value where only i'th bit is set
	// value & (1 << i)) is non-zero only if i'th bit is set in value
	if (value & (0x80 >> i))
    	printf("1");
	else
		printf("0");
	}
}

int main(void) {
	unsigned char a = 0x69;  // 01101001
	unsigned char b = 0xca;  // 11001010

	printf("a & b = %02x\n", a & b);

	unsigned char c = a | b;

	printf("a | b = %02x\n", c);

	b ^= a;  // b = b ^ a
	printf("a ^ b = %02x\n", b);

	printf("~a = %02x\n", ~a);
	printf("~a & 0xff = %02x\n", ~a & 0xff);

    printf("0x69 = ");
    printBits(a);
    printf("\n");
    printBits2(a);
    printf("\n0x69 << 2 = ");
    printBits(a << 2);
    printf("\n");

}
