# XOR-cipher

Implementing functions:

* `void confidentiality_xor(uint32_t key, void *data, int len)` - each 32-bit data block will be encrypted using the encryption key.


* `void **confidentiality_xor_shift**(uint32_t key, void *data, int len)` - similar to the above function however, after each 32-bit block, the key is shifted 1 bit left and the shifted bit at the beginning is moved to the end bit of the key.

* *len* indicates the number of 32-bit blocks of data


### * Note:
