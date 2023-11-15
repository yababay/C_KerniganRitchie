#include <stdio.h>

int main() {
    printf("\y"); // warning: unknown escape sequence
    printf("\a");
    printf("\u"); // error: incomplete universal character name
}
