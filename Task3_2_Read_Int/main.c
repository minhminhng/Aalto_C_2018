#include <stdio.h>

int read_int(int *number)
{
    int ret;
    if (number == NULL) { // Tarkistetaan annetu osoitin
        return -1; // Osoittimen ollessa epäkelpo, funktiosta poistutaan
    }
    ret = scanf("%d", number);
    if (ret != 1) { // Tarkistetaan onnistuiko lukeminen
        return -1;
    }
    return *number;
}

int main(void)
{
    int a;
    int *ptr_a = &a;
    int ret = read_int(ptr_a);
    if (ret != -1)
        printf("reading succeeded: %d\n", a);
    else
        printf("not a valid number\n");

    // Toinen tapa samalle asialle
    read_int(&a);
    printf("r: %d\n", ret);
}
