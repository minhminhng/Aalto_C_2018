#include <stdio.h>
#include "tcpheader.h"

int main()
{
    /* Feel free to modify this function to test different things */

    unsigned char bytes[] = {
        0x12,0x34,0x45,0x67,0xaa,0xbb,0xcc,0xdd,
        0xee,0xff,0xaa,0xbb,0xb1,0x5c,0x08,0x00,
        0x12,0x34,0x00,0x00 };
    
    printf("Source port: %04x\n", getSourcePort(bytes));
    //printf(" %lu\n", sizeof(bytes));
    setSourcePort(bytes, 0x2325);
    printf("Source port: %04x\n", getSourcePort(bytes));
    printf("Destination port: %04x\n", getDestinationPort(bytes));
    printf("ACK flag: %d\n", getAckFlag(bytes));
    printf("Data Offset: %d\n", getDataOffset(bytes));    
    setDataOffset(bytes, 6);
    printf("Data Offset: %d\n", getDataOffset(bytes));    
}
