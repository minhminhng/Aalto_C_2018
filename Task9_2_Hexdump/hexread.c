#include <stdio.h>
#include <stdlib.h>
#include "hexread.h"



int dump_hex(const char *filename)
{
	FILE *f = fopen(filename, "r");
	if (!f){
		return -1;
	}
	unsigned int count = 0;
	int c = getc(f);
	while (c != EOF) {	
		for (unsigned int i = 0; i < 16 && c != EOF; i ++){
			count++;
			printf("%02x ", c);
			c = getc(f);
		}
		if (c != EOF){
			printf("\n");
		}
	}
	return count;
}
