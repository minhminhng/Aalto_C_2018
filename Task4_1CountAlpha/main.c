#include <stdio.h>
#include <ctype.h>

int count_alpha(const char *str){
	unsigned int count = 0;
	while (*str){
		if (isalpha(*str)){
			count++;
		}
		str++;
	}
	return count;
}

void clean_spaces(char *str)
{
    while (*str != '\0') {  // Repeat until we are at the end of the string
        if (*str == ' ') {  // is it a space?
            *str = '.';  // replace it with a period
        }
        str++;  // move pointer to the next character
    }
}

int main(void)
{
    char message[] = "It is going to rain tomorrow";
    int count = count_alpha(message);
    clean_spaces(message);
    printf("modified: %s\n", message);
    return 0;
}
