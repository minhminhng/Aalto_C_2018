/* Example of a macro with debugger
/// The program can only be properly executed using gcc -DDEBUG macros.c
// #include <stdio.h>
//
// #ifdef DEBUG
// #define MYDEBUG(Msg) fprintf(stderr, "File: %s, Line: %d: %s", \
// 							 __FILE__, __LINE__, Msg)
// #else
// #define MYDEBUG(Msg)
// #endif
//
// int main(void) {
// 	MYDEBUG("Starting\n");
// 	for (int a = 0; a < 10; ) { a++; }
// 	MYDEBUG("At the end\n");
// } */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "macros.h"

int main(void)
{
#ifdef EQ3
    printf("Testing EQ3:\n");
    printf("EQ3(3,3,3) returned %d, should have been 1.\n", EQ3(3,3,3));
    printf("EQ3(1,2,3) returned %d, should have been 0.\n", EQ3(1,2,3));
#else
    printf("Implement EQ3 first");
#endif

#ifdef MIN3
    printf("\nTesting MIN3:\n");
    printf("MIN3(1,2,3) returned %d, should have been 1.\n", MIN3(1,2,3));
    printf("MIN3(4,1,6) returned %d, should have been 1.\n", MIN3(4,1,6));
#else
    printf("Implement MIN3 first");
#endif

    return 0;
}
