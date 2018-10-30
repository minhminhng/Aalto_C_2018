#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "xorcipher.h"

/*
 * Encrypts / decrypts the void* buffer named <data>
 * Encrypted data will be saved to the same <data> -buffer.
 * Encryption is based on XOR operation using a 32-bit <key>
 */
void confidentiality_xor(uint32_t key, void* data, int len)
{
	for (unsigned int k = 0; k < len; k++)
	{
		uint32_t new = (((uint32_t *)data)[k]) ^ (key);
		memcpy(&(data[k*4]), &new, sizeof(uint32_t));
	}
}

/*
 * Encrypts / decrypts the void* buffer named <data>
 * Encrypted data will be saved to the same <data> -buffer.
 * Encryption is based on XOR operation using a 32-bit <key>
 * After encrypting one 32-bit block of original data, the key shifts one bit left
 */
void confidentiality_xor_shift(uint32_t key, void* data, int len)
{
    for (unsigned int k = 0; k < len; k++)
	{
		uint32_t new = (((uint32_t *)data)[k]) ^ (key);
		memcpy(&(data[k*4]), &new, sizeof(uint32_t));
        key = (key << 1) | (key >> 31) ;
	}
}

void print_uint32_hex(void* data, int len)
{
	for(int i = 0; i < len; i++){
		printf("0x%08x ", ((uint32_t*)data)[i]);
	}
	printf("\n");
}
