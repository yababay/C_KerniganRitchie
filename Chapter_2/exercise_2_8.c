#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main() {
    printf("%x\n", rightrot(0x12345678, 8)); /* 0x78123456 */
    printf("%x\n", rightrot(0x12345678, 0)); /* 0x12345678 */
    printf("%x\n", rightrot(0x12345678, 1)); /* 0x91a2b3c */
    return 0;
}

unsigned int rightrot(unsigned int x, int n) {
    return (x >> n) | ((~(~0 << n) & x) << (8*sizeof(int) - n));
}
