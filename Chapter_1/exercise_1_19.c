#include <stdio.h>

#define MAX_LINE 1000

int getline_c(char line[], int lim);
void reverse(char s[]);

int main() {
    int len;
    char line[MAX_LINE];

    while ((len = getline_c(line, MAX_LINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

int getline_c(char line[], int lim) {
    int c, i;

    for (i=0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim-1) {
            line[i] = c;
        }
    }
    if (c == '\n') {
        if (i < lim-1) {
            line[i] = c;
            ++i;
        }
        else {
            line[lim-2] = '\n';
        }
    }
    if (i < lim) {
        line[i] = '\0';
    }
    else {
        line[lim-1] = '\0';
    }
    return i;
}

void reverse(char s[]) {
    int i, k;
    char temp;

    for (i = 0; s[i] != '\n' && s[i] != '\0'; i++)
        ;
    
    for (i -= 1, k = 0; i > k; --i, ++k) {
        temp = s[i];
        s[i] = s[k];
        s[k] = temp;
    }
}
