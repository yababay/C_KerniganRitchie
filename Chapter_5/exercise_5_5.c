#include <stdio.h>

void strncpy_c(char *s, char *t, int n);
void strncat_c(char *s, char *t, int n);
int strncmp_c(char *s, char *t, int n);

int main() {
    char s[20] = "Hello, ";
    char t[] = "world!";
    char r[20];

    strncpy_c(r, s, 10);
    printf("%s\n", r);

    strncpy_c(r, t, 3);
    printf("%s\n", r);

    strncat_c(s, t, 10);
    printf("%s\n", s);

    strncat_c(r, "ld!", 1);
    printf("%s\n", r);

    printf("%d\t%d\t%d\n", strncmp_c(s, "Hello, world!", 20),
            strncmp_c("Hello", "Helo", 3),
            strncmp_c("Hello", "Helo", 5));

    return 0;
}

void strncpy_c(char *s, char *t, int n) {
    while ((n-- > 0) && (*s++ = *t++))
        ;
}

void strncat_c(char *s, char *t, int n) {
    while (*s != '\0') {
        s++;
    }
    while ((n-- > 0) && (*s++ = *t++))
        ;
}

int strncmp_c(char *s, char *t, int n) {
    for (; --n > 0 && *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}
