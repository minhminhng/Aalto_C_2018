#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 'strchr' searches character 'c' from string 'str'
 * and returns pointer to it. If the character cannot
 * be found, the function return NULL. Function can
 * also match the final nil character, i.e., if you
 * give '\0' as c, the function returns pointer to
 * the end of the string
 */
char* mystrchr(char* str, char c)
{
    do {
        if (*str == c)
            return str;
    } while (str++);
    if (c == '\0') {
        while(*str) {
            str++;
        }
        return str;
    }
    return NULL;
}

/* 'createArray' dynamically allocates memory to store an integer array of
 * size numbers, and initializes the array by increasing integers, starting
 * from 0. The function returns pointer to the beginning of the array.
 */
int* createArray(unsigned int size)
{
    int* array = malloc(size * sizeof(unsigned int));
    if (array == NULL) {
        return NULL;
    }
    for (unsigned int i = 0; i < size; i++) {
        array[i] = i;
    }
    return array;
}

/* 'addProduct' adds a new item (of type struct products) at the end
 * of dynamically allocated array, and initializes the item as indicated
 * in arguments 'newtitle' and 'newprice'. The earlier length of the table
 * is indicated by argument 'length'. Function returns pointer to the
 * beginning of the extended array.
 */
struct products {
    char* title;
    double price;
};

struct products* add_product(struct products* array, unsigned int length,
                             const char* newtitle, double newprice)
{
    struct products* np = realloc(array,
                                 (length+1) * sizeof(struct products));
    (&np[length])->title = malloc((strlen(newtitle) + 1) *sizeof (char));
    strcpy((&np[length])->title, newtitle);
    (&np[length])->price = newprice;
    return np;
}

int main(void) {
    char* mystr1 = "Today is another day!";
    printf("mystr1 starts at %p, the first 'y' character is found at %p.\n", mystr1,
            mystrchr(mystr1, 'y'));
    printf("mystr1 starts at %p, the '\\0' character is found at %p.\n", mystr1,
            mystrchr(mystr1, '\0'));

    int* arr1 = createArray(12);
    for (unsigned int i = 0; i < 12; i++) {
        printf("%d ", arr1[i]);
    }
    putchar('\n');
    free(arr1);
    arr1 = createArray(3);
    for (unsigned int i = 0; i < 3; i++) {
        printf("%d ", arr1[i]);
    }
    putchar('\n');
    free(arr1);

    struct products list[] = {{"Day cream", 10.5},
                              {"Eye cream", 22.7},
                              {"Hand cream", 4.6}};

    struct products* newlist = NULL;

    unsigned int len = 0;
    for (unsigned int i = 0; i < sizeof(list) / sizeof(struct products); i++) {
        struct products* pro = add_product(newlist, len, (&list[len])->title, list[len].price);
        if (!pro) {
            exit(EXIT_FAILURE);
        }
        newlist = pro;
        len++;
    }

    for (unsigned int i = 0; i < len; i++) {
        printf("Product %d is %s and has price %.2f.\n", i+1, (&newlist[i])->title, (&newlist[i])->price);
    }
    for (unsigned int i = 0; i < len; i++) {
        free((&newlist[i])->title);
    }
    free (newlist);

    return EXIT_SUCCESS;
}
