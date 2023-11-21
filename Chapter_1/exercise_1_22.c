#include <stdio.h>

#define COLUMNS 3
#define MAX_LINE 25

int getline_col(char line[], int len);

int main() {
    int len;
    char s[MAX_LINE];

    len = 0;
    while ((len = getline_col(s, MAX_LINE)) > 1) {
        printf("%s", s);
    }
    return 0;
}

int getline_col(char line[], int len) {
    int c, i, cols, is_col_break;
    
    i = cols = is_col_break = 0;
    for (; i < len-2 && cols < COLUMNS && (c=getchar()) != EOF && c != '\n';) {
        if (c == ' ' || c == '\t') {
            if (i == 0) {
                continue;
            }
            if (!is_col_break) {
                is_col_break = 1;
                cols++;
            }
        }
        else {
            is_col_break = 0;
        }
        line[i++] = c;
    }
    if (is_col_break) {
        --i;
    }
    line[i++] = '\n';
    line[i] = '\0';
    return i;
}
