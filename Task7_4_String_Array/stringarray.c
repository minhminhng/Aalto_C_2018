#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringarray.h"

/* Initializes the string array to contain the initial
 * NULL pointer, but nothing else.
 * Returns: pointer to the array of strings that has one element
 *      (that contains NULL)
 */
char **init_string_array(void)
{
	char **newStr = malloc(sizeof(char *));
	*newStr = NULL;
	return newStr;
}

/* Releases the memory used by the strings.
 */
void release_string_array(char **arr)
{
	while(*arr){
		while(**arr){
			free(**arr);
			(**arr)++;
		}
		free(*arr);
		(*arr)++;
	}
	free(arr);
}

/* Exercise b: Add <string> to the end of array <array>.
 * Returns: pointer to the array after the string has been added.
 */
char **insert_string(char **arr, const char *str)
{
	unsigned int org = sizeof(char *);
	//printf("%lu\n", org);
	char **newStr;
	newStr = malloc(2* sizeof (char *));
	//printf("%lu\n", sizeof(newStr));
	printf("%p ", newStr);
	while(*newStr != NULL){
		*newStr = *arr;
		printf("%p ", newStr);
		(*newStr)++;
	}
	*newStr = str;
	printf("%p ", str);
	printf("%p ", newStr);
	printf("%p ", newStr[0]);
	printf("%p ", newStr[1]);
	(*newStr)++;
	*newStr = NULL;
	return newStr;
}

/* Exercise c: reorder strings in <array> to lexicographical order */
void sort_string_array(char **arr)
{
}

/* You can use this function to check what your array looks like.
 */
void print_string_array(char **arr)
{
    if (!arr)
        return;
    while (*arr) {
        printf("%s  ", *arr);
        arr++;
    }
    printf("\n");
}
