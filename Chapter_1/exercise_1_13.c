#include <stdio.h>

#define MAX_WORD_LENGTH 15

int main() {
    int i, k, c;
    int wls[MAX_WORD_LENGTH];

    for (i = 0; i < MAX_WORD_LENGTH; ++i) {
        wls[i] = 0;
    }

    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t') {
            if (i > MAX_WORD_LENGTH) {
                wls[MAX_WORD_LENGTH-1]++;
                i = 0;
            }
            else if (i > 0) {
                wls[i-1]++;
                i = 0;
            }
        }
        else {
            i++;
        }
    }

    if (i > MAX_WORD_LENGTH) {
        wls[MAX_WORD_LENGTH-1]++;
    }
    else if (i > 0) {
        wls[i-1]++;
    }

    putchar('\n');
    for (i = 0; i < MAX_WORD_LENGTH; ++i) {
        for (k = 0; k < wls[i]; ++k) {
            putchar('#');
        }
        putchar('\n');
    }
    return 0;
}
