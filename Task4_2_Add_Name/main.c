#include <string.h>
#include <stdio.h>

void addname(char *buffer, const char *addme, unsigned int maxsize)
{	
	strncat(buffer, addme, maxsize - strlen(buffer)-1);
	strncat(buffer, ",", maxsize - strlen(buffer)-1);
}


int main(void)
{
    char result[30] = { 0 }; // fills result with all zeros

    addname(result, "Reiska", 30);
    addname(result, "Bilbo Reppuli", 30);
    addname(result, "Henri Hinaaja", 30);
    addname(result, "Urpo Turpo", 30);

    printf("We have: %s\n", result);
    const char *expected = "Reiska,Bilbo Reppuli,Henri Hi";
    printf("We expected: %s\n", expected);
    if (!strcmp(result, expected)) {
	printf("Looking good!\n");
    } else {
	printf("Not quite right...\n");
    }

    return 0;
}
