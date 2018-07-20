#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *mystrcat(char *dest, const char *src)
{
    unsigned int len = strlen(src) + strlen(dest) + 1;
    char *origdest = realloc(dest, len * sizeof(char));
    char *new = origdest;
    //dest = new;
    printf("%lu ", sizeof(origdest));
    if (origdest == NULL) {
		free(dest);
		free(origdest);
		return NULL;
	}
    while(*origdest) {
        origdest++;
    }

    while (*src) {
        *origdest++ = *src++;  // Copies character and increases/moves pointer
    }
    *origdest = 0;
    origdest = new;

    return origdest;
}

int main(void)
{
    char *str = malloc(7);
    strcpy(str, "Aatami");
    
    
    str = mystrcat(str, "Beetami");
    printf("%s\n", str);
    free(str);
}
