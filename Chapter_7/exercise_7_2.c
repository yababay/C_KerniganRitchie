#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
#define HEXLEN 3

int inc(int, int);

int main() {
    int c, pos = 0;

    while ((c=getchar()) != EOF) {
        if (iscntrl(c) || c == ' ') {
            pos = inc(pos, HEXLEN);
            printf("\\%3x", c);

            if (c == '\n') {
                pos = 0;
                putchar('\n');
            }
        }
        else {
            pos = inc(pos, 1);
            putchar(c);
        }
    }
    return 0;
}

int inc(int p, int i) {
    if (p + i < MAXLINE) {
        return p + i;
    }

    putchar('\n');
    return i;
}
