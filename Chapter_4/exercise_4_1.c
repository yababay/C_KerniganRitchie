#include <stdio.h>

int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main() {
    printf("%d\n", strindex("Could you, would you", pattern)); /* 12 */
    printf("%d\n", strindex("ould", pattern)); /* 0 */
    printf("%d\n", strindex("Can you, will you", pattern)); /* -1 */

    return 0;
}

int strindex(char s[], char t[]) {
    int i, j, k, found;

    found = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0') {
            found = i;
        }
    }
    return found;
}
