#include <stdio.h>

#define TAB_COUNT 4
#define MAX_LINE 1000

int getline_replace_space(char line[], int lim);
void replace_space(char line[], int lim);

int main() {
    int len;
    char s[MAX_LINE];

    while ((len = getline_replace_space(s, MAX_LINE)) > 0) {
        printf("%s", s);
    }
    return 0;
}

int getline_replace_space(char line[], int lim) {
    int c, i;

    for (i=0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim-1) {
            line[i] = c;
        }
    }
    if (c == '\n') {
        if (i < lim-1) {
            line[i++] = c;
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
    replace_space(line, lim);
    return i;
}

void replace_space(char line[], int lim) {
    int i, cur, is_tab, k;

    for (i = 0, cur = 0; i < lim;) {
        if (line[i] == ' ') {
            k = i;
            do {
                is_tab = line[i++] == ' ';
            } while (i < lim && i%TAB_COUNT);
            if (is_tab) {
                line[cur++] = '\t';
            }
            else {
                for (; k < i; cur++, k++) {
                    line[cur] = line[k];
                }
            }
        }
        else {
            line[cur++] = line[i++];
        }
    }
}
