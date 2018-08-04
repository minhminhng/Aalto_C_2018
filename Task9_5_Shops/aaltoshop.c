#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aaltoshop.h"


int output_binary(const char* filename, Product* shop)
{
	/* Output a binary format file from given Product array
	 */ 
	
	FILE *f = fopen(filename, "w");
	if (!f){
		printf("Error opening file!\n");
		exit(1);
	}
	
	unsigned int count = 0;
	while (shop[count].name[0] != 0){
		//printf("%s \n", shop[count].name);
		fwrite(&shop[count], sizeof(Product), 1, f);
		count++;
	}
	
	fclose(f);
	return 0;
}

Product* read_binary(const char* filename)
{
	/* Read a binay format file and outputs the read data into a Product-array
	 * ret: the pointer to the array. 
	 */ 
	FILE *f = fopen(filename, "rb");
	if (!f){
		return NULL;
	}
	
	Product *shop = malloc(sizeof(Product));
	Product new;
	if (!shop){
		return NULL;
	}
	unsigned int count = 0;
	while(fread(&new, sizeof(Product), 1, f)){
		strcpy(shop[count].name, new.name);
		shop[count].price = new.price;
		shop[count].in_stock = new.in_stock;		
		count++;
		
		shop = realloc(shop, sizeof(Product) * (count + 1));
	}
	shop = realloc(shop, sizeof(Product) * (count + 1));
	shop[count].name[0] = 0;
	fclose(f);
	return shop;
}

int output_plaintext(const char* filename, Product* shop)
{
	/* Output a plain text file from given Product array
	 */ 
	FILE *f = fopen(filename, "w+");
	if (!f){
		printf("Error opening file!\n");
		exit(1);
	}
	unsigned int count = 0;
	char buffer[1000];
	while (shop[count].name[0] != 0){
		sprintf(buffer, "%s %.1f %d\n", shop[count].name, 
				shop[count].price, shop[count].in_stock);
		fputs(buffer, f);
		count++;
	}
	//sprintf(buffer, "%s \n", 0);
	//fputs(buffer, f);
	fclose(f);
	return 0;
}

Product* read_plaintext(const char* filename)
{
	/* Read a binay format file and outputs the read data into a Product-array
	 * ret: the pointer to the array. 
	 */
	FILE *f = fopen(filename, "r");
	if (!f){
		printf("Error opening file!\n");
		return NULL;
	}
	
	Product *shop = malloc(sizeof(Product));
	char line[1000];

	unsigned int count = 0;

	if (!shop){
		return NULL;
	}
	while (fgets(line, 1000, f)){
		sscanf(line, "%s %f %d", shop[count].name, &shop[count].price, &shop[count].in_stock);
		//printf("name = %s, price = %.1f, in_stock = %d\n", shop[count].name, 
				//shop[count].price, shop[count].in_stock);	
		count++;
		shop = realloc(shop, sizeof(Product) * (count + 1));
	}
	//printf("%d ", count);
	shop = realloc(shop, sizeof(Product) * (count + 1));
	shop[count].name[0] = 0;
	fclose(f);
	return shop;
}
