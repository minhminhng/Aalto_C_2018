#ifndef AALTO_BITS_H
#define AALTO_BITS_H

// returns value 0, if bit value in i is zero and returns value 1, if bit value in i is one
int op_bit_get(const unsigned char* data, int i);

// sets a bit in input data
void op_bit_set(unsigned char* data, int i);

// resets a bit in input data
void op_bit_unset(unsigned char* data, int i);

// seperate how_many bits long binary number from the array
unsigned char op_bit_get_sequence(const unsigned char* data, int i, int how_many);

// print one unsigned char's binary representation
void op_print_byte(unsigned char b);

#endif
