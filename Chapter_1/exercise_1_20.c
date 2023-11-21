#include <stdio.h>

#define TAB_COUNT 4
#define MAX_LINE 1000

int getline_replace_tab(char line[], int lim);

int main() {
    int len;
    char s[MAX_LINE];

    while ((len = getline_replace_tab(s, MAX_LINE)) > 0) {
        printf("%s", s);
    }
    return 0;
}

int getline_replace_tab(char line[], int lim) {
    int c, i;

    for (i=0; (c = getchar()) != EOF && c != '\n';) {
        if (i < lim-1) {
            if (c == '\t') {
                do {
                    line[i] = ' ';
                    i++;
                } while (i < lim-1 && i%TAB_COUNT);
            }
            else {
                line[i] = c;
                i++;
            }
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
