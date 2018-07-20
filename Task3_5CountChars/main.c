#include <stdio.h>

unsigned int arraylen(const char *array){
	unsigned int count = 0;
	const char *temp;
	temp = array;
	while (*temp++ != 0){
		count++;	// 0 is the end of the array
	}
	return count;
}

void countchars(const char *array, unsigned int *counts){
	/* Count the number of each character in a array*/
	const char *temp;
	temp = array;
	while (*temp){
		for (unsigned int i = 0; i < 256; i++){
			if (*temp == i){
				counts[i]++;
			}
		}
		temp++;
	}
}

void printcounts(int min, int max, const unsigned int *counts) {
    for (int i = min; i <= max; i++) {
        printf("%c: %u  ---  ", i, counts[i]);
        if ((i - min + 1) % 6 == 0)
            printf("\n");
    } 
}

void printarray(const char *array) {
    printf("{ ");
    while (*array) {
        printf("'%c',", *array);
        array++;
    }
    printf("0 }");
}

int main()
{
     unsigned int counts[256] = { 0 };

     char sample[] = { 'a','b','r','a','c','a','d','a','b','r','a',0 };

     printf("%s, length: %u\n", sample, arraylen(sample));
     
     countchars(sample, counts);
     printcounts('a', 'z', counts);

    return 0;
}
