#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

int getop(char* s);
void push(double d);
double pop(void);

int sp = 0;
double val[MAXVAL];

int main(int argc, char *argv[]) {
    int type;
    double op2;
    
    if (argc < 2) {
        printf("Usage: expr <expression>\n");
        return 0;
    }

    while ((type = getop(*++argv)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(*argv));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                }
                else {
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                return 0;
            default:
                printf("error: unknown command %s\n", *argv);
                break;
        }
    }
    return 0;
}

int getop(char *s) {
    int c;

    if (s == NULL) {
        return '\n';
    }

    c = *s;
    if (!isdigit(c) && c != '.') {
        return c;
    }
    if (isdigit(c)) {
        while (isdigit(c = *++s))
            ;
    }
    if (c == '.') {
        while (isdigit(c = *++s))
            ;
    }

    if (c != '\0') {
        return EOF;
    }
    return NUMBER;
}

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    }
    else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
