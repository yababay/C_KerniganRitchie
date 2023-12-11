#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char s[]);
void push(double f);
double pop(void);
int getch(void);
void ungetch(int c);
void print_top(void);
void copy_top(void);
void swap_top(void);
void clear(void);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case 'P':
                print_top();
                break;
            case 'C':
                copy_top();
                break;
            case 'S':
                swap_top();
                break;
            case 'D':
                clear();
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
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push(((int)pop()) % ((int)op2));
                }
                else {
                    printf("error: zero modulo operand\n");
                }
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'c':
                push(cos(pop()));
                break;
            case 'p':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                clear();
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
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

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    if (!isdigit(c) && c != '-' && c != '.') {
        return c;
    }
    i = 0;
    if (c == '-') {
        if (isdigit(s[++i] = c = getch())) {
            while (isdigit(s[++i] = c = getch()))
                ;
        }
        else {
            ungetch(c);
            return '-';
        }
    }
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
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

void print_top(void) {
    if (sp == 0) {
        printf("print_top: stack is empty\n");
    }
    else {
        printf("print_top: %.8g\n", val[sp-1]);
    }
}

void copy_top(void) {
    if (sp == 0) {
        printf("copy_top: stack is empty\n");
    }
    else {
        push(val[sp-1]);
    }
}

void swap_top(void) {
    int temp;

    if (sp < 2) {
        printf("swap_top: stack has less than two elements\n");
    }
    else {
        temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
    }
}

void clear(void) {
    while (sp > 0) {
        pop();
    }
}
