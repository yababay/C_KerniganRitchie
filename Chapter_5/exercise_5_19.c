#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 1000
#define BUFSIZE 100

enum { NAME, PARENS, BRACKETS };

int gettoken(void);
int tokentype;
char token[100];
char out[100];

int getch(void);
void ungetch(int);

char buf[BUFSIZE];
int bufp = 0;

int main() {
    int type, p_pending;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {
        strcpy(out, token);
        p_pending = 0;
        while ((type = gettoken()) != '\n') {
            if (type == PARENS || type == BRACKETS) {
                if (p_pending) {
                    sprintf(temp, "(%s)", out);
                    strcpy(out, temp);
                }
                strcat(out, token);
                p_pending = 0;
            }
            else if (type == '*') {
                sprintf(temp, "*%s", out);
                strcpy(out, temp);
                p_pending = 1;
            }
            else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
                p_pending = 0;
            }
            else {
                printf("Invalid input at %s\n", token);
                p_pending = 0;
            }
        }
        printf("%s\n", out);
    }
    return 0;
}

int gettoken(void) {
    int c;
    char *p = token;

    while ((c=getch()) == ' ' || c == '\t')
        ;

    if (c == '(') {
        if ((c=getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;

        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); ) {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else {
        return tokentype = c;
    }
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else {
        buf[bufp++] = c;
    }
}
