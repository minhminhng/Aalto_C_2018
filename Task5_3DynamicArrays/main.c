#include <stdio.h>
#include <stdlib.h>

int *dynamic_reader(unsigned int n)
{
	int *newA = malloc(n * sizeof(int));
	int temp;
	
	if (newA == NULL)
	{
		return NULL;
	}
	for (unsigned int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		*(newA + i) = temp;
	}
	return newA;
}

int *insert_into_array(int *arr, unsigned int num, int newval)
{
	int *newA = malloc((num + 1) * sizeof (int));
	
	if (newA == NULL)
	{
		free(arr);
		return NULL;
	}
	for (unsigned int i = 0; i < num; i ++)
	{
		*(newA + i) = *(arr+i);
	}
	*(newA + num) = newval;
	free(arr);
	return newA;
}

int main(void)
{
	int n = 3;
	int *array = dynamic_reader(n);
	for (unsigned int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	for (unsigned int i = 0; i < 5; i++)
	{
		array = insert_into_array(array, n + i, i);
	}
	for (unsigned int i = 0; i < n + 5; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	free(array);
	return 0;
}
