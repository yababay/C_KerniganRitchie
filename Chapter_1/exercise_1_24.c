#include <stdio.h>

#define MAX_DEPTH 1000

int main() {
    int c;
    int comments, about_to, error, in_quotes, in_dquotes, escape;
    
    int st[MAX_DEPTH];
    int cur;

    about_to = comments = cur = error = in_quotes = in_dquotes = escape = 0;

    while (!error && (c = getchar()) != EOF) {
        if (escape == 1) {
            if (c != 'a' && c != 'b' && c != 'e' && c != 'f' &&
                    c != 'n' && c != 'r' && c != 't' && c != 'v' &&
                    c != '\\' && c != '\'' && c != '\"' && c != '?' &&
                    c != 'x' && c != 'u' && c != 'U') {
                error = 1;
            }
            escape = 0;
        }
        else if (c == '/' && !in_dquotes) {
            if (about_to) {
                about_to = 0;
                comments = 0;
            }
            else {
                about_to = 1;
            }
        }
        else if (c == '*' && !in_dquotes) {
            if (about_to) {
                about_to = 0;
                if (comments) {
                    error = 1;
                }
                else {
                    comments = 1;
                }
            }
            else {
                about_to = 1;
            }
        }
        else {
            about_to = 0;
            if (c == '(' && !in_quotes && !in_dquotes && !comments) {
                st[cur++] = 1;
            }
            else if (c == ')' && !in_quotes && !in_dquotes && !comments) {
                if (cur == 0 || st[--cur] != 1) {
                    error = 1;
                }
            }
            else if (c == '{' && !in_quotes && !in_dquotes && !comments) {
                st[cur++] = 2;
            }
            else if (c == '}' && !in_quotes && !in_dquotes && !comments) {
                if (cur == 0 || st[--cur] != 2) {
                    error = 1;
                }
            }
            else if (c == '[' && !in_quotes && !in_dquotes && !comments) {
                st[cur++] = 3;
            }
            else if (c == ']' && !in_quotes && !in_dquotes && !comments) {
                if (cur == 0 || st[--cur] != 3) {
                    error = 1;
                }
            }
            else if (c == '\'' && !comments) {
                if (in_quotes) {
                    in_quotes = 0;
                }
                else {
                    in_quotes = 1;
                }
            }
            else if (c == '\"' && !comments) {
                if (in_dquotes) {
                    in_dquotes = 0;
                }
                else {
                    in_dquotes = 1;
                }
            }
            else if (c == '\\' && !comments) {
                escape = 1;
            }
        }
    }

    if (error || cur != 0 || in_quotes || in_dquotes || comments) {
        printf("There are errors!\n");
    }
    else {
        printf("No errors!\n");
    }

    return 0;
}
