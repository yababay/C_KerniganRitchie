#include <stdio.h>
#include <limits.h>

void itoa(int n, char s[], int mwidth);
void reverse(char s[], int len);

int main() {
    char r1[129], r2[129], r3[129];
    itoa(INT_MAX, r1, 11);
    itoa(-3435, r2, 8);
    itoa(INT_MIN, r3, 11);
    printf("%s,%s,%s\n", r1, r2, r3);
    return 0;
}

void itoa(int n, char s[], int mwidth) {
    int i, sign;
    unsigned un;

    if ((sign = n) < 0) {
        un = -n;
    }
    else {
        un = n;
    }
    i = 0;

    do {
        s[i++] = un % 10 + '0';
    } while ((un /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    for(; i < mwidth; i++) {
        s[i] = ' ';
    }

    s[i] = '\0';
    reverse(s, i);
}

void reverse(char s[], int len) {
    int c, i, j;

    for (i = 0, j = len-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
