#include <stdio.h>

#define MAX_LINE 1000

int getline_c(char s[], int lim);

int main() {
    int len;
    char line[MAX_LINE]; 

    while ((len = getline_c(line, MAX_LINE)) > 0) {
        if (len > 2) {
            printf("%s", line);
        }
    }
    return 0;
}

int getline_c(char s[], int lim) {
    int i, k, c;

    for (i = 0, k = -1; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
        if (c != ' ' && c != '\t') {
            k = i;
        }
    }
    k++;
    if (c == '\n') {
        s[k] = c;
        k++;
    }
    s[k] = '\0';
    return k;
}
