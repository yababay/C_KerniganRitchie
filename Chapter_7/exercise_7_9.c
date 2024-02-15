#include <stdio.h>

int isupper_c(char);

int main() {
    printf("%d\t%d\n", isupper_c('T'), isupper_c('b'));
    return 0;
}

int isupper_c(char c) {
    return c >= 'A' && c <= 'Z';
}
