#include <stdio.h>
#include <ctype.h>
#include <string.h>

/***
 * Implement a function with the following interface: 
 * char *shout(char *dest, const char *src). Function argument 
 * src points to the string that you should modify as described below.
 * The modified string will be written at address dest. 
 * In addition the function should return pointer to 
 * the modified string (i.e., to the same address dest originally
 * points to).
 * The string should be modified in the following ways:
 *  - all letter characters should be changed to upper case. 
 *  - If the original string has a question mark ('?'), 
 * it should be changed to exclamation mark ('!').
 *  - If the original string has period ('.'), 
 * it should be replaced with three exclamation marks.
 */

char *shout(char *dest, const char *src)
{
	char *temp;
	temp = dest;
	while(*src)
	{
		if isalpha(*src){
			*dest = toupper(*src);
			dest++;
		}
		else if (*src == '?'){
			*dest = '!';
			dest++;
		}
		else if(*src == '.'){
			*dest = '!';
			*(dest+1) = '!';
			*(dest+2) = '!';
			dest += 3;
		}
		else
		{
			*dest = *src;
			dest++;
		}
		src++;
	}
	*dest = '\0';
	dest = temp;
	return dest;
}

int main(void)
{
	char dest[200];

	/* The following helps detecting string errors, e.g. missing final nil */
	memset(dest, '#', 199);
	dest[199] = 0;

	printf("%s",
	   shout(dest,
		 "Otatko makkaraa? Se maksaa kaksi euroa. Ole hyvä.\n"));

	printf("%s",
	   shout(dest,
		 "Minnekäs rouva on matkalla? Terveyskeskus on tuolla päin.\n"));

	return 0;
}
