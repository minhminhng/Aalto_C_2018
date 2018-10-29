# Bitmasks

Bit masks are used to operate on selected bit or set of bits. State of bits can be investigated using the bitwise AND operator, and bit masks can be combined using the bitwise OR operator. The result of bitwise AND operation is true (non-zero) only if at least one of the indicated bits is set.

The program deals with the array, which is consist of several bytes.

a) Basic operations

In the following functions, data parameter indicates start of the array and i parameter denotes position of the bit in the input array.

Implement the following functions which manipulates bit of input array:

`void op_bit_set(unsigned char* data, int i)` -- sets a bit in input data.

`void op_bit_unset(unsigned char* data, int i)` -- resets a bit in input data.

`int op_bit_get(const unsigned char* data, int i)` -- returns value 0, if bit value in i is zero and returns value 1, if bit value in i is one.

b) Print a byte

Implement function `void op_print_byte(unsigned char b)`, which prints one unsigned char's binary representation.

c) Get a sequence

Implement function `unsigned char op_bit_get_sequence(const unsigned char* data, int i, int how_many)`, that separates a maximum of 8 bits long binary number from the array and returns it. i and data have same meaning as above. how_many indicates how many bits need to be counted from the i (max. 8). If how_many is less than 8, the most significant bits of the returned number is left with zeros. In this task, you may want to take advantage of function implemented in (a).

Notes:

In this task, bit 0 is the most significant bit. It is also assumed that unsigned char is exactly 8 bits (1 byte). Thus, for example, bit 8 is a leftmost bit in second unsigned char byte and bit 17 is the second highest bit in the third unsigned char byte. Thus, examining the number 170 (0xAA hexadecimal format, 10101010 in binary), the most significant bit, ie bit 0 has a value of 1.
