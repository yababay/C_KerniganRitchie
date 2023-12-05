#include <stdio.h>
#include <limits.h>

void itob(int n, char s[], int b);
void reverse(char s[], int len);

int main() {
    char r1[129], r2[129], r3[129];
    itob(INT_MAX, r1, 2);
    itob(-3435, r2, 10);
    itob(INT_MIN, r3, 16);
    printf("%s\t%s\t%s\n", r1, r2, r3);
    return 0;
}

void itob(int n, char s[], int b) {
    int i, sign, mod;
    unsigned un;

    if ((sign = n) < 0) {
        un = -n;
    }
    else {
        un = n;
    }
    i = 0;

    do {
        mod = un % b;
        if (mod < 10) {
            s[i++] = mod + '0';
        }
        else {
            s[i++] = mod + 'a' - 10;
        }
    } while ((un /= b) > 0);

    if (sign < 0) {
        s[i++] = '-';
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
