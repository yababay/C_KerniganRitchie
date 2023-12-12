#include <stdio.h>
#include <limits.h>

#define MAXLENGTH 20

void itoa(int n, char s[]);
static int itoa_r(unsigned n, char s[], int i);

int main() {
    char s[MAXLENGTH];
    
    itoa(123, s);
    printf("%s\n", s);

    itoa(0, s);
    printf("%s\n", s);

    itoa(INT_MAX, s);
    printf("%s\n", s);

    itoa(INT_MIN+1, s);
    printf("%s\n", s);

    itoa(INT_MIN, s);
    printf("%s\n", s);

    return 0;
}

void itoa(int n, char s[]) {
    int i = 0;
    unsigned un;
    
    if (n < 0) {
        un = -n;
        s[i++] = '-';
    }
    else {
        un = n;
    }
    i += itoa_r(un, s, i);
    s[i] = '\0';
}

int itoa_r(unsigned n, char s[], int i) {
    int shift = 0;

    if (n / 10) {
        shift = itoa_r(n / 10, s, i);
        s[shift+i] = n % 10 + '0';
        return ++shift;
    }
    else {
        s[i++] = n % 10 + '0';
        return 1;
    }
    return 0;
}
