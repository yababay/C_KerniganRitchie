#include <stdio.h>

#define BUFSIZE 1000

int getch(void);
void ungetch(int c);

int buf[BUFSIZE];
int bufp = 0;

int main() {
    ungetch('a');
    ungetch('b');
    printf("%c\n", getch());
    printf("%c\n", getch());
    printf("%d\n", getch()); /* -1 for EOF */
    return 0;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else {
        buf[bufp++] = c;
    }
}
