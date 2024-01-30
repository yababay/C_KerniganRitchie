#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TOLOWERNAME "./tolower"

int main(int argc, char **argv) {
    int c, tl = 0;

    if (strcmp(*argv, TOLOWERNAME) == 0) {
        tl = 1;
    }

    while ((c = getchar()) != EOF) {
        if (tl) {
            putchar(tolower(c));
        }
        else {
            putchar(toupper(c));
        }
    }
    return 0;
}
