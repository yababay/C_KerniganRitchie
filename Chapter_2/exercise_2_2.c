#include <stdio.h>

#define MAXLINE 1000

int main() {
    char c, s[MAXLINE];
    int i, is_okay;

    i = 0;

    do {
        if (i >= MAXLINE - 1) {
            is_okay = 0;
        }
        else if ((c=getchar()) == '\n') {
            is_okay = 0;
        }
        else if (c == EOF) {
            is_okay = 0;
        }
        else {
            is_okay = 1;
            s[i++] = c;
        }
    } while (is_okay);

    s[i++] = '\n';
    s[i] = '\0';
    printf("%s", s);
    return 0;
}
