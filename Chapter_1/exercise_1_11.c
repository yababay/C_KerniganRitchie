#include <stdio.h>

#define IN  1
#define OUT 0

/* test cases:
 * empty input
 * input without words
 * input like '\n\n\n\n\n\n\n\n'
 * one word input
 * two or more lines that start with words
 */
int main() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
            state = OUT;
        }
        else if (c == ' ' || c == '\t') {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
    return 0;
}
