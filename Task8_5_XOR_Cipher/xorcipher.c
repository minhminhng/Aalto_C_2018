#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "xorcipher.h"



/*
 * Encrypts / decrypts the void* buffer named <data>
 * Encrypted data will be saved to the same <data> -buffer.
 * Encryption is based on XOR operation using a 32-bit <key>
 */
void confidentiality_xor(uint32_t key, void* data, int len)
{
	printf("%lu \n", len * sizeof(uint32_t));
	unsigned int *newKey = malloc(len * sizeof(uint32_t));
	//unsigned int *newKey = malloc(len * sizeof(uint32_t));
	//*data = * (unsigned int)*data;
	for (unsigned int k = 0; k < len; k++)
	{
		newKey[k] = newKey[k] | key;
	}
	print_uint32_hex(newKey, len);
	printf("\n");
	data  = (void *)((uintptr_t)data ^ (uintptr_t)newKey);
	//print_uint32_hex(data, len);
	printf("\n");
	free(newKey);
}

/*
 * Encrypts / decrypts the void* buffer named <data>
 * Encrypted data will be saved to the same <data> -buffer.
 * Encryption is based on XOR operation using a 32-bit <key>
 * After encrypting one 32-bit block of original data, the key shifts one bit left
 */
void confidentiality_xor_shift(uint32_t key, void* data, int len)
{

}

void print_uint32_hex(void* data, int len)
{
	for(int i = 0; i < len; i++) printf("0x%08x ", ((uint32_t*)data)[i]);
	printf("\n");
}

