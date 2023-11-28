#include <stdio.h>

int lower(int c);

int main() {
    printf("%c\t%c\t%c\n", lower('b'), lower('B'), lower('0')); /* b b 0 */
    return 0;
}

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
