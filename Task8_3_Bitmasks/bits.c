#include <stdio.h>
#include <string.h>
#include "bits.h"

int op_bit_get(const unsigned char* data, int i)
{
	data = data + (i / 8);
	int new = * data & (1 << (7- (i % 8)));
	if (new){
		return 1;
	}
	return 0;
}

void op_bit_set(unsigned char* data, int i)
{
	unsigned char* cur = data;
	data = data + (i / 8);         // Move the pointer to the group of 8 bits including the bit should be set.
	* data |= 1 << (7 - (i % 8));   // Set the bit accordingly.
	data = cur;
}

void op_bit_unset(unsigned char* data, int i)
{
	unsigned char set = 0;
	unsigned char* cur = data;
	data = data + (i / 8);
	for (unsigned int k = 0; k < 8; k++){
		if (k != (7 - (i % 8))){
			set |= 1 << (k);
		}
	}
	* data &= set;
	data = cur;
}

unsigned char op_bit_get_sequence(const unsigned char* data, int i, int how_many)
{
	unsigned char extract = 0;
	unsigned char* cur = data;
	data = data + (i / 8);
	if ((i / 8) == ((i + how_many - 1) / 8))
	{
		* cur = * cur >> (8 - (i + how_many) % 8);
		for (unsigned j = 0; j < 8 - how_many; j++){
			op_bit_unset(cur, j);
		}
		extract = * cur;
		return extract;
	}
	else
    {
		unsigned int sen = (i + how_many) % 8;		// the number of bit from the second byte
		for (unsigned j = 0; j < 8 - how_many + sen; j++){
			op_bit_unset(cur, j);
		}
		extract = (* cur << sen) | (* (cur + 1) >> ( 8 - sen));
		return extract;
	}
}

void op_print_byte(unsigned char b)
{
	for (int i = 7; i >= 0; i--) {
			if (b & (1 << i))
			   	printf("1");
			else
				printf("0");
	}
}
