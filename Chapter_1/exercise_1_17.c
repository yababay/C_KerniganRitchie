#include <stdio.h>

#define MAXLINE 1000
#define MINLINE 80

int getline_c(char s[], int lim);

int main() {
    int l;
    char line[MAXLINE];

    while ((l = getline_c(line, MAXLINE)) > 0) {
        if (l > MINLINE) {
            printf("%s", line);
        }
    }
    return 0;
}

int getline_c(char s[], int lim) {
    int c, i;

    for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim-1) {
            s[i] = c;
        }
    }
    if (c == '\n') {
        if (i < lim-1) {
            s[i] = c;
            ++i;
        }
        else {
            s[lim-2] = '\n';
        }
    }
    if (i < lim) {
        s[i] = '\0';
    }
    else {
        s[lim-1] = '\0';
    }
    return i;
}
