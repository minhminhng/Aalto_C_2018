#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "filestats.h"


int line_count(const char *filename)
{
	int line = 0;
	FILE *f = fopen(filename, "r");
	if (!f){
		return -1;
	}
	char buf[100];
	while(fgets(buf, sizeof(buf), f) != NULL){
		if (strlen(buf) > 0 && strcmp(buf, "\n") != 0){
			line++;
		}
	}
	fclose(f);
	return line;
}


int word_count(const char *filename)
{
	int word = 0;
	FILE *f = fopen(filename, "r");
	if (!f){
		return -1;
	}
	char c;
	c = getc(f);

	while (c != EOF) {
		if (isalpha(c))
		{
			if ((c = getc(f)) == ' ' || c == '\n' || c == '\t'){
				word++;
			}
		}
		else {
			c = getc(f);
		}
	}
	fclose(f);
	return word;
}
