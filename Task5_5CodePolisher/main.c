#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *delete(char *input, int start, int end)
{
	unsigned int newlength = strlen(input) + start - end;
	char *new = malloc(sizeof(char) * newlength);
	
	unsigned int startlength = 0;
	if (new == NULL) {
		return NULL;
	}
	for (unsigned int i = 0; i < strlen(input); i++) {
		if (i < start || i > end){
			new[startlength++] = input[i];
		}	
	}
	new[startlength] = '\0';
	free(input);
	return new;
}

char *delete_comments(char *input)
{
	for (unsigned int i = 0; i < strlen(input); i++) {
		if (*(input + i) == '/' && *(input + i + 1) == '/') {
			for (unsigned int j = i + 2; j < strlen(input); j++) {
				if (*(input + j) == '\n'){
					printf("%d %d \n", i, j);
					input = delete(input, i, j);
					break;
				}
			}
			 i--;
		}
		else if (*(input + i) == '/' && *(input + i + 1) == '*') {
			for (unsigned int j = i + 2; j < strlen(input); j++) {
				if (*(input + j) == '*' && *(input + j + 1) == '/') {
					input = delete(input, i, j + 1);
					break;
				}				
			}	
			i--;
		}
	}	
	return input;
}


/* Read given file <filename> to dynamically allocated memory.
 * Return pointer to the allocated memory with file content, or
 * NULL on errors.
 */
char *read_file(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return NULL;
    
    char *buf = NULL;
    unsigned int count = 0;
    const unsigned int ReadBlock = 100;
    unsigned int n;
    do {
        buf = realloc(buf, count + ReadBlock + 1);
        n = fread(buf + count, 1, ReadBlock, f);
        count += n;
    } while (n == ReadBlock);
    
    buf[count] = 0;
    
    return buf;
}


int main(void)
{
    char *code = read_file("testify.c");
    if (!code) {
        printf("No code read");
        return -1;
    }
    printf("-- Original:\n");
    fputs(code, stdout);
    
    code = delete_comments(code);
    printf("-- Comments removed:\n");
    fputs(code, stdout);
   
    free(code);
    return 0;
}
