#include <stdio.h>
 
int bitcount(unsigned x);

int main() {
    printf("%d\n", bitcount(0)); /* 0 */
    printf("%d\n", bitcount(1)); /* 1 */
    printf("%d\n", bitcount(01110)); /* 3 */
    printf("%d\n", bitcount(01101010101)); /* 6 */
    printf("%d\n", bitcount(01000000000)); /* 1 */
    return 0;
}

int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x &= (x-1)) {
        b++;
    }
    return b;
}

/* 
 * There are two cases of x:
 * 1) x ends with 1, so it is
 * x = nnnnnn1
 * then
 * x-1 = nnnnnn0
 * So, x & (x-1) is nnnnnn0, which reduces number of 1s by 1
 *
 * 2) x ends with 0, so it is
 * x = nnnnn1(0)0
 * then
 * x-1 = nnnnn0(1)1
 * So, x & (x-1) is nnnnn0(0)0, which again reduces number of 1s by 1
 */
