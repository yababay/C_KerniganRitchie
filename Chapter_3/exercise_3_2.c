#include <stdio.h>

#define MAXLENGTH 1000

void escape(char s[], const char t[]);

int main() {
    char s[MAXLENGTH];
    char t[] = "Hello,\tworld!\n\'\b\"Program is working\?\"";
    escape(s, t);
    printf("%s\n", s);
    return 0;
}

void escape(char s[], const char t[]) {
    int i, j;
    i = j = 0;
    while (t[i] != '\0' && j < MAXLENGTH-2) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                i++;
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                i++;
                break;
            case '\b':
                s[j++] = '\\';
                s[j++] = 'b';
                i++;
                break;
            case '\r':
                s[j++] = '\\';
                s[j++] = 'r';
                i++;
                break;
            case '\'':
                s[j++] = '\\';
                s[j++] = '\'';
                i++;
                break;
            case '\"':
                s[j++] = '\\';
                s[j++] = '\"';
                i++;
                break;
            case '\\':
                s[j++] = '\\';
                s[j++] = '\\';
                i++;
                break;
            case '\?':
                s[j++] = '\\';
                s[j++] = '\?';
                i++;
                break;
            default:
                s[j++] = t[i++];
                break;
        }
    }
    s[j] = '\0';
}
