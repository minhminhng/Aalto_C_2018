#include <stdio.h>

int array_sum(int *array, int count)
{
	unsigned sum = 0;
	for (unsigned int i = 0; i < count; i++)
	{
		sum += *(array + i);
	}
	return sum;
}

int array_reader(int *vals, int count)
{
	int a = 0;
	unsigned int i;
	for (i = 0; i < count; i++){
		int ret = scanf("%d", &a);
		if (ret < 1){
			return i;
		}
		else {
			*(vals + i) = a;
		}		
	}
	return i;
}

int main(void)
{
	int valarray[] = {10, 100, 1000};
	int ret = array_sum(valarray, sizeof(valarray)/sizeof(int));
	printf("%d\n", ret);
	int array[10];
	int n = array_reader(array, 10);
	printf("%d numbers read\n", n);
	int i;
	for (i = 0; i < n; i++){
		printf("%d ", array[i]);
	}
	return 0;
}
