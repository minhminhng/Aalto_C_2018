#include <stdio.h>

void swap(int *n1, int *n2){
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;	
}

void sort(int *start, int size){
	for (unsigned int i = 0; i < size - 1; i++){
		int jMin = i;
		for (unsigned int j = i + 1; j < size; j++){
			if (*(start + j) < *(start + jMin)){
				jMin = j;
			}
		}
		if (jMin != i){
			swap((start + i), (start + jMin));
		}
	}	
}

int main(void){
	int array[10] = {2, 23 , 4, 5, 21, 56, 65, 1, 8, 1};
	sort(array, 10);
	for (unsigned int i = 0; i < sizeof(array)/sizeof(int); i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
