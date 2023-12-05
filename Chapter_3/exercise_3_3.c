#include <stdio.h>

#define MAXLENGTH 1000

void expand(char s1[], char s2[]);
void strcpy_c(char s1[], char s2[]);

int main() {
    char s1[] = "a-z";
    char s2[] = "a-b-c";
    char s3[] = "a-z0-9";
    char s4[] = "-a-z";
    char s5[] = "ac-d5-";
    char s6[] = "a--d";
    char s7[] = "f-b";
    char s8[] = "!";
    char s[MAXLENGTH];
    expand(s1, s);
    printf("%s\n", s);
    strcpy_c(s, "");
    expand(s2, s);
    printf("%s\n", s);
    strcpy_c(s, "");
    expand(s3, s);
    printf("%s\n", s);
    strcpy_c(s, "");
    expand(s4, s);
    printf("%s\n", s);
    strcpy_c(s, "");
    expand(s5, s);
    printf("%s\n", s);
    strcpy_c(s, "");
    expand(s6, s);
    printf("%s\n", s);
    strcpy_c(s, "");
    expand(s7, s);
    printf("%s\n", s);
    strcpy_c(s, "");
    expand(s8, s);
    printf("%s\n", s);
    return 0;
}

void expand(char s1[], char s2[]) {
    char start, end;
    int i, j, is_hyphen;
    start = end = 0;

    for (i = 0, j = 0, is_hyphen = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '-') {
            if (!start) {
                s2[j++] = '-';
            }
            else if (is_hyphen) {
                strcpy_c(s2, "Incorrect pattern");
                return;
            }
            else {
                is_hyphen = 1;
            }
        }
        else if ((s1[i] >= 'a' && s1[i] <= 'z') ||
                (s1[i] >= 'A' && s1[i] <= 'Z') ||
                (s1[i] >= '0' && s1[i] <= '9')) {
            if (start) {
                if (is_hyphen) {
                    end = s1[i];
                    if (start > end) {
                        strcpy_c(s2, "Incorrect pattern");
                        return;
                    }
                    for (; start <= end; start++) {
                        s2[j++] = start;
                    }
                    start = end = is_hyphen = 0;
                }
                else {
                    s2[j++] = start;
                    start = s1[i];
                }
            }
            else {
                start = s1[i];
            }
        }
        else {
            strcpy_c(s2, "Incorrect pattern");
            return;
        }
    }
    if (strt) {
        s2[j++] = start;
    }
    if (is_hyphen) {
        s2[j++] = '-';
    }
    s2[j] = '\0';
}

void strcpy_c(char s1[], char s2[]) {
    int i = 0;

    while ((s1[i] = s2[i])) {
        i++;
    }
}
