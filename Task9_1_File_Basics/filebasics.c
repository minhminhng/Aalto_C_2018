#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filebasics.h"

int print_file(const char *filename)
{
	/* Read the file with filename and print to the standard output 
	 */ 
	FILE *f = fopen(filename, "r");
	if (!f){
		return -1;
	}
	unsigned int count = 0;
	unsigned int c;
	while ((c = getc(f)) != EOF){
		putchar(c);
		count++;
	}
	fclose(f);
	return count;
	
}

char *difference(const char* file1, const char* file2)
{
	/* Compare the two file and print the first different line between them
	 * */
	FILE *f1 = fopen(file1, "r");
	FILE *f2 = fopen(file2, "r");
	
	if (!f1 | !f2){
		fclose(f1);
		fclose(f2);
		return NULL;
	}
	
	char s1[100];
	char s2[100];
	
	//fgets(s1, 100, f1);
	//fgets(s2, 100, f2);
	int cmp = 0;
	do{
		//cmp  0 && *s1 != EOF && *s2 != EOF){
		fgets(s1, 100, f1);
		fgets(s2, 100, f2);
		cmp = strcmp(s1, s2);	
	} while (cmp == 0 && s1 != NULL && s2 != NULL);
	char con[] = "----\n";
	char *s = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + strlen(con) + 1));
	if (cmp == 0){
		free(s);
		fclose(f1);
		fclose(f2);
		return NULL;
	}
	else {		
		s = strcpy(s, s1);
		s = strcat(s, con);
		s = strcat(s, s2);
		fclose(f1);
		fclose(f2);
		return s;
	}
}
