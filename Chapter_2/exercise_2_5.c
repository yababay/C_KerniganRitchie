#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    /* 0   6   -1 */
    printf("%d\t%d\t%d\n", any("Hello", "H"), any("Hello, world", "dr w"),
            any("Hello", "abcd"));
    return 0;
}

int any(char s1[], char s2[]) {
    int res, i, j;

    for (res = -1, i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j] && (res == -1 || (res > -1 && i < res))) {
                res = i;
            }
        }
    }
    return res;
}
