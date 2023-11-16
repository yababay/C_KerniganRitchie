#include <stdio.h>

#define MAX_SYMBOL 128

int main() {
    int i, k, c;
    int fc[MAX_SYMBOL];

    for (i = 0; i < MAX_SYMBOL; ++i) {
        fc[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        fc[c]++;
    }

    putchar('\n');
    for (i = 0; i < MAX_SYMBOL; ++i) {
        for (k = 0; k < fc[i]; ++k) {
            putchar('#');
        }
        putchar('\n');
    }
    return 0;
}
