#include <stdio.h>
#include <string.h>

int count_substr(const char *str, const char *sub)
{
	int count = 0;
	while (*str)
	{
		char *newL = strstr(str, sub);
		if (newL != NULL){
			count++;
			str = newL + strlen(sub);
		}
		else {
			return count;
		}
	}
	return count;
}

int main(void)
{
	char *myStr = "one two one twotwo three";
	char *sub = "two";
	int count = count_substr(myStr, sub);
	printf("\"%s\" appears %d time(s) in \"%s\".\n", sub, count, myStr);
	
	return 0;	
}
