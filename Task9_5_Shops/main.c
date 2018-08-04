#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aaltoshop.h"


int main()
{
	Product* arr = calloc(3,  sizeof(Product));
	strcpy(arr[0].name, "peanut_butter");
	arr[0].price = 5.2;
	arr[0].in_stock = 4;
	strcpy(arr[1].name, "milk");
	arr[1].price = 1.1;
	arr[1].in_stock = 42;
	arr[2].name[0] = 0;
	
	output_binary("testi", arr);
	
	Product* arr2;
	arr2 = read_binary("testi");

	for(int i = 0; i < 2; i++)
		{
			printf("%s %.1f %d\n", arr2[i].name, arr2[i].price, arr2[i].in_stock);
		}

	output_plaintext("testi2.txt", arr2);

	Product* arr3 = NULL;

	arr3 = read_plaintext("testi2.txt");

	for(int i = 0; i < 2; i++)
	{
		printf("%s %f %d\n", arr3[i].name, arr3[i].price, arr3[i].in_stock);
	}
	free(arr);
	free(arr2);
	free(arr3);

	return 0;
}
