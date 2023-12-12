#include <stdio.h>

int getch(void);
void ungetch(int c);

int buf = '\0';

int main() {
    ungetch('a');
    ungetch('b');
    printf("%c\n", getch());
    printf("%c\n", getch());
    return 0;
}

int getch(void) {
    int res;

    if (buf != '\0') {
        res = buf;
        buf = '\0';
        return res;
    }
    return getchar();
}

void ungetch(int c) {
    if (buf != '\0') {
        printf("ungetch: too many characters\n");
    }
    else {
        buf = c;
    }
}
