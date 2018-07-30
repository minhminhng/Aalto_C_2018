#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

/***
 * Implement similar function in <string.h> but the line stops with '?'
 * instead of '\0'.
 ***/

void es_print(const char *s)
{
	while (*s != '?')
	{
		printf("%c", *s);
		s++;
	}
}

unsigned int es_length(const char *s)
{
	unsigned int length = 0;
	while (*s != '?'){
		length++;
		s++;
	}
	return length;
}

int es_cat(char *dst, char *src)
{
	/***
	 * Concatenate the src to the dst before the '?'
	 */
	int length = 0;
	char *temp;
	temp = dst;
	while(*dst != '?')
	{
		dst++;
		length++;
	}
	
	while(*src != '?')
	{
		*dst++ = *src++;
		length++;			
	}
	*dst = *src;
	dst = temp;
	return length;
}

const char *es_strstr(const char *str1, const char *str2)
{
	/***
	 * Find the first location of str2 in str2 before '?' 
	 */
	const char *temp;
	unsigned int length = strlen(str2) -1;
	const char *temp2;
	temp2 = str2;
	unsigned int i = 0;
	while(*str1 != '?'){
		while (*str1 == *str2 && *str2 != '?'){
			i++;
			if (i == 1){
				temp = str1;
			}
			if (i == length){
				return temp;
			}
			str1++;
			str2++;	
		}
		i = 0;
		str1++;
		str2 = temp2;
	}
	return NULL;
}

int main(void)
{
	char *str = "Auto ajoi?kilparataa";
	es_print(str);
	printf("\n");
	printf("%d\n", es_length(str));
	char str1[] = "Hellotelel?hotme";
	char str2[] = "yes?no";
	printf("%d\n", es_cat(str1, str2));
	//es_print(str1);
	char *s1 = "one twotwo three four? one";
	char *s2 = "four?";
	es_print(s2);
	printf(" appears at location %p\n", es_strstr(s1, s2));
	return 0;
}
