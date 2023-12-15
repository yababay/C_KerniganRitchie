#include <stdio.h>

int strend(char *s, char *t);

int main() {
    char *s = "Hello, world";
    char *t;

    t = s + 10;
    printf("%d\n", strend(s, t));

    t = "";
    printf("%d\n", strend(s, t));

    t = "abcd";
    printf("%d\n", strend(s, t));

    t = "ello, world";
    printf("%d\n", strend(s, t));
    
    printf("%d\n", strend(s, s));

    t = "Oh, Hello, world";
    printf("%d\n", strend(s, t));

    return 0;
}

int strend(char *s, char *t) {
    char *sc, *tc;

    sc = s;
    tc = t;
    while (*sc != '\0') {
        sc++;
    }
    while (*tc != '\0') {
        tc++;
    }

    while (sc >= s && tc >= t) {
        if (*sc-- != *tc--) {
            return 0;
        }
    }
    return (tc < t);
}
