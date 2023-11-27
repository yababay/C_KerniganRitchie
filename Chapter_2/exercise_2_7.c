#include <stdio.h>

int invert(unsigned int x, int p, int n);

int main() {
    printf("%x\n", invert(0xffff, 7, 4)); /* 0xff0f */
    printf("%x\n", invert(0xdb42, 9, 8)); /* 0xd8be */
    return 0;
}

int invert(unsigned int x, int p, int n) {
    return (~(~0 << n) << (p-n+1)) ^ x;
}
