#include <stdio.h>

int setbits(unsigned int x, int p, int n, unsigned int y);

int main() {
    printf("%x\n", setbits(0xffff, 7, 4, 0x2468)); /* 0xff8f */
    printf("%x\n", setbits(0xdb42, 9, 8, 0x402a)); /* 0xd8aa */
    return 0;
}

int setbits(unsigned int x, int p, int n, unsigned int y) {
    return ((~(~(~0 << n) << (p-n+1))) & x) | (~(~0 << n) & y) << (p-n+1);
}
