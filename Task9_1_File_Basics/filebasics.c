#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filebasics.h"

int print_file(const char *filename){
	FILE *fp;
	fp = fopen(filename,"r");
    if (!fp) {
    	return -1;
    }
	int c = fgetc(fp);
	int count = 0;
	while(c!=EOF){
		printf("%c", c);
		c = fgetc(fp);
		count++;
	}
    fclose(fp);
	return count;
}

char* difference(const char *file1, const char* file2){
	FILE *fp1, *fp2;

	fp1 = fopen(file1,"r");
	fp2 = fopen(file2,"r");
    if (!fp1 || !fp2) {
    	exit(EXIT_FAILURE);
    }

    // Allocate memory for the buffers
    char * buf = malloc(1000*sizeof(char));
	char buf1[100];
	char buf2[100];

	while ((fgets(buf1,sizeof(buf1),fp1)!=NULL) && (fgets(buf2,sizeof(buf2),fp2)!=NULL)) {
        while (!strcmp(buf1, "\n")) {
            fgets(buf1,sizeof(buf1),fp1);
        }

        if (!strcmp(buf2, "\n")) {
            fgets(buf2,sizeof(buf2),fp2);
        }

		if(strcmp(buf1,buf2)!=0)
		{
			char *p = buf;
			char *p1 = buf1;
			char *p2 = buf2;
			while(*p1 != '\0'){
				*p++ = *p1++;
			}
			for(int i = 0; i<4; i++){
				*p++='-';
			}
			*p++='\n';
			while(*p2 != '\0'){
				*p++ = *p2++;
			}
			*p ='\0';
		    fclose(fp1);
		    fclose(fp2);
			return buf;
		}
	}

    fclose(fp1);
    fclose(fp2);
	return NULL;
}
