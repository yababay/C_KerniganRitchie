#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUMBER '0'

int getline_c(char *s, int lim);
int atoi(char *s);
void itoa(int n, char *s);
void reverse(char *s);
int strindex(char *s, char *t);
int getop(char *s);

int main() {
    char s[] = "Hello, world!";
    char t[20];
    char y[10];

    printf("Enter up to 20 symbols:\n");
    getline_c(t, 20);
    printf("%s\n", t);

    reverse(s);
    printf("%s\n", s);

    printf("%d\n", atoi("450"));

    itoa(-653, y);
    printf("%s\n", y);
    
    printf("%d\t%d\n", strindex("Hello", "ll"), strindex("Hello", "elk"));

    printf("Enter operation: ");
    printf("%c\n", getop(y));
    return 0;
}

int getline_c(char *s, int lim) {
    int c, n;

    n = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
        n++;
    }
    if (c == '\n') {
        *s++ = c;
        n++;
    }
    *s = '\0';
    return n;
}

int atoi(char *s) {
    int n, sign;

    while (*s && isspace(*s))
        ;

    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') {
        s++;
    }

    n = 0;
    while (isdigit(*s)) {
        n = 10 * n + (*s++ - '0');
    }
    return sign * n;
}

void itoa(int n, char *s) {
    char *sc;
    int sign;

    if ((sign = n) < 0) {
        n = -n;
    }

    sc = s;
    do {
        *sc++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        *sc++ = '-';
    }
    *sc = '\0';
    reverse(s);
}

void reverse(char *s) {
    char *t;
    char c;

    for (t = s + strlen(s)-1; s < t; s++, t--) {
        c = *s;
        *s = *t;
        *t = c;
    }
}

int strindex(char *s, char *t) {
    char *sc, *tc;
    int i = 0;

    while(*s) {
        sc = s;
        tc = t;
        while (*tc && *tc == *sc) {
            tc++;
            sc++;
        }
        if (!*tc && *tc != *s) {
            return i;
        }
        i++;
        s++;
    }
    return -1;
}

int getop(char *s) {
    static int un = EOF;
    int c;

    if (un != EOF && un != ' ' && un != '\t') {
        *s = c = un;
    }
    else {
        while ((*s = c = getchar()) == ' ' || c == '\t')
            ;
    }

    *(++s) = '\0';
    if (!isdigit(c) && c != '-' && c != '.') {
        un = EOF;
        return c;
    }
    if (isdigit(c)) {
        while (isdigit(*(++s) = c = getchar()))
            ;
    }
    if (c == '.') {
        while (isdigit(*(++s) = c = getchar()))
            ;
    }
    *s = '\0';
    un = c;
    return NUMBER;
}
