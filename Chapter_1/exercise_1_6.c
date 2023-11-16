#include <stdio.h>

int main() {
    int value;

    value = getchar() != EOF;
    printf("%d\n", value); // prints 0 if Ctrl-D pressed, 1 otherwise
    return 0;
}
