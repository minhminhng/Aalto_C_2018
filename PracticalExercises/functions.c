#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 'mystrcat' function concatenates string 'src' after string 'dst'.
 * The function does not allocate memory, but it assumes that
 * the calling function arranges the memory somehow (as with
 * the original strcat function). The function returns pointer
 * to the beginning of the string.
 */
char* mystrcat(char* dest, const char* src) {
    // char new[1000];
    char *new = malloc((strlen(dest) + strlen(src) + 1) * sizeof(char));
    char* res = new;
    unsigned int count = 0;
    while (*dest) {
        new[count] = *dest;
        dest++;
        count++;
    }

    while (*src){
        new[count] = *src;
        src++;
        count++;
    }
    new[count] = '\0';
    return res;
}

/*
 * 'pickmax' function processes table numbers that contains
 * unsigned integers. The table ends with number 0. The
 * function should return the largest integer in the table.
 */
unsigned int pickmax(unsigned int *numbers) {
    unsigned int max = 0;

    while (*numbers != 0) {
        if (*numbers > max) {
            max = *numbers;
        }
        numbers++;
    }
    return max;
}

/*
 * 'set_bit' goes through 'n' bytes starting from address buffer,
 * and sets bit number 'bit' on in each of the bytes. The most
 * significant bit is numbered 7, and the least significant bit
 * is numbered 0.
 */
void print_bits(unsigned char *buf) {
    for (unsigned int i = 0; i < 8; i++) {
        if (*buf & (1<< (7 - i))) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
}
void set_bit(unsigned char *buffer, unsigned int n, int bit) {
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < bit; j++) {
            buffer[i] |= 1 << j;
        }
    }

    while (*buffer) {
        printf("0x%02x\n", *buffer);
        buffer++;
    }
    putchar('\n');
}

int main(void) {

    char *dst1 = "Good morning! ";
    char *src1 = "Nice to meet you.";
    char *new1 = mystrcat(dst1, src1);
    printf("Result1: %s\n", new1);

    char *dst2 = "Hello Minh Minh! ";
    char *src2 = "Where are you going to?";
    char *new2 = mystrcat(dst2, src2);
    printf("Result1: %s\n", new2);

    char *dst3 = "Nho! ";
    char *src3 = "Thoi gian da qua...";
    char *new3 = mystrcat(dst3, src3);
    printf("Result1: %s\n", new3);
    free(new1);
    free(new2);
    free(new3);

    unsigned int list1[] = {2, 4, 6, 12, 35, 32, 5, 26, 0};
    printf("The largest integer in list1 is %d, should be 35.\n", pickmax(list1));

    unsigned int list2[] = {100, 27, 54, 298, 64, 3859, 35, 0};
    printf("The largest integer in list2 is %d, should be 3859.\n", pickmax(list2));

    unsigned int list3[] = {33, 1258, 2656, 987, 12, 0};
    printf("The largest integer in list3 is %d, should be 2656.\n", pickmax(list3));

    unsigned char buf1[100] = {0};
    set_bit(buf1, 7, 4);

    unsigned char buf4[100]  = {0};
    set_bit(buf4, 15, 6);

    unsigned char buf3[100]  = {0};
    set_bit(buf3, 7, 2);

    return EXIT_SUCCESS;
}
