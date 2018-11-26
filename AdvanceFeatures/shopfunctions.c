#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shopfunctions.h"

/* Compare two strings lexically (ASCII value-wise, same as strcmp())
 * The string "duck" is before "rabbit" in this order but
 *  "Rabbit" is before "duck" (see an ASCII chart)
 * Returns: 0 if the two strings are equal
 */
int compareAlpha(const void* a, const void* b) {
    const Product* a1 = a;
    const Product* b1 = b;
    return strcmp(a1->name, b1->name);
}

/* Same as compareAlpha but compares the product *in_stock* numerically.
 * The product with higher *in_stock* -value should be first in the array.
 * If there are two or more products with same *in_stock* -value, they are compared lexically.
 */
int compareNum(const void* a, const void* b) {
    const Product* a1 = a;
    const Product* b1 = b;
    return (a1->in_stock > b1->in_stock) ? -1 : ((a1->in_stock < b1->in_stock) ? 1 : compareAlpha(a1, b1));
}

/* Finds a product from a sorted array of products
 * Returns: Whatever bsearch returned.
 * IMPORTANT: Remember that bsearch takes a pointer to a type as first parameter, and
 * pointer to an array with same type elements as in first parameter.
 */
Product* findProduct(Product* p_array, const char* searchkey, int (*cmp)(const void*, const void*)) {

    int count = 0;
    while (strcmp(p_array[count].name, "\0")) {
        count++;
    }

    // void* bsearch (const void* key, const void* base,
    //            size_t num, size_t size,
    //            int (*compar)(const void*,const void*));
    // Since searchkey is only a char and bsearch needs the type of key similar to the type of base

    // Create a struct and assign the searchkey to the name of the struct
    Product* search = malloc(sizeof(Product));
    if (search == NULL) {
        return NULL;
    }
    strcpy(search->name, searchkey);

    Product* result = bsearch(search, p_array, count, sizeof(Product), cmp);
    free(search);

    return result;
}
