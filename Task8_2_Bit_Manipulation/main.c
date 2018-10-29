#include <stdio.h>


/* Implement function mergeBits which takes two 4 bit number as input values
 * and returns a 8 bit value. This 8 bit value is formed from the two input
 * values a and b. The value a forms the 4 higher order bits of the return
 * value whereas b forms 4 lower order bits of the return value.
 * For example, when a function is called as follows: mergeBits (0x6, 0xD),
 * then result will be eight-bit number, which is the hexadecimal
 * representation 6D.
 */
unsigned char mergeBits(unsigned char a, unsigned char b)
{
	return (((a & 0xF) << 4) | b);
}

int main()
{
    printf("%02X\n", mergeBits(0x5, 0xE));
    printf("%02X\n", mergeBits(0xA, 0xC));
    printf("%02X\n", mergeBits(0xD, 0x2));
}
