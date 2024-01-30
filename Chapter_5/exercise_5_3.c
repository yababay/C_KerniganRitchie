#include <stdio.h>

#define MAXLENGTH 1000

void strcat_c(char *s, char *t);

int main() {
    char s[MAXLENGTH] = "Hello, ";
    char e[MAXLENGTH] = "";

    strcat_c(s, "world!");
    printf("%s\n", s);

    strcat_c(s, e);
    printf("%s\n", s);

    strcat_c(e, s);
    printf("%s\n", s);

    return 0;
}

void strcat_c(char *s, char *t) {
    while (*s != '\0') {
        s++;
    }
    while ((*s++ = *t++))
        ;
}
