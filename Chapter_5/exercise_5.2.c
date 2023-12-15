#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

int getfloat(double *pn);
int getch(void);
void ungetch(int);

char buf[BUFSIZE];
int bufp = 0;

int main() {
    double n;

    for (; getfloat(&n) != EOF;) {
        printf("%f\n", n);
    }
    return 0;
}

int getfloat(double *pn) {
    int c, sign;
    double power;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    if (c == '.') {
        c = getch();
    }
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10;
    }
    *pn *= sign / power;

    if (c != EOF) {
        ungetch(c);
    }
    return c;
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
