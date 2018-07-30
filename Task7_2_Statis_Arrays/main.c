#include <stdio.h>

int main(void)
{
	/* 
	 * Define a two dimensinal 6x6 static array with
	 * name taulu. Value stored in each array index
	 * must be the product of row and column index
	 * */ 
	int taulu[6][6];
	for (unsigned int j = 0; j < 6; j++){
		for (unsigned int i = 0; i < 6; i++){
			taulu[j][i] = j * i;
		}
	}
	for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%2d ", taulu[j][i]);
        }
        printf("\n");
    }
	return 0;
}
