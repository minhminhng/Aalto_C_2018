#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myprint(const char *str, ...)
{
    va_list args;
    va_start(args, str);
    int count = 0;

    while (*str) {
        if (*str == '&') {
            printf("%d", va_arg(args, int));
            count++;
        }
        else {
            putchar(*str);
        }
        str++;
    }

    va_end(args);      // End and free the va_list
    return count;
}

int main(void)
{
    myprint("Hello!\n");
    myprint("Number: &\n", 5);
    myprint("Number one: &, number two: &\n", 120, 1345);
    int ret = myprint("Three numbers: & & &\n", 12, 444, 5555);
    myprint("I just printed & integers\n", ret);

    return 0;
}
