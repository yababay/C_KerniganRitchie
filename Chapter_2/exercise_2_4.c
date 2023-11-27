#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
    char s1[] = "Hello, world!";
    char s2[] = ",!ahw";
    squeeze(s1, s2);
    printf("%s\n", s1); /* Hello orld */
    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j, k, found;

    for (i = j = 0; s1[i] != '\0'; ++i) {
        for (found = k = 0; s2[k] != '\0'; ++k) {
            if (s1[i] == s2[k]) {
                found = 1;
            }
        }
        if (!found) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}
