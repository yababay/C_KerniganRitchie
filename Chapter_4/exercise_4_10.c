#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define MAXLINE 1000

int getline_c(int s[]);
int getop(char s[]);
void push(double f);
double pop(void);
void print_top(void);
void copy_top(void);
void swap_top(void);
void clear(void);

int sp = 0;
double val[MAXVAL];
int line[MAXLINE];
int line_i = 0;

int main() {
    int type, len;
    double op2;
    char s[MAXOP];

    while ((len = getline_c(line)) > 0) {
        line_i = 0;
        while ((type = getop(s)) != '\0') {
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
    }
    return 0;
}

int getline_c(int s[]) {
    int c, i;

    for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
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

    while ((s[0] = c = line[line_i++]) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    if (!isdigit(c) && c != '-' && c != '.') {
        return c;
    }
    i = 0;
    if (c == '-') {
        if (isdigit(s[++i] = c = line[line_i++])) {
            while (isdigit(s[++i] = c = line[line_i++]))
                ;
        }
        else {
            line_i--;
            return '-';
        }
    }
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = line[line_i++]))
            ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = line[line_i++]))
            ;
    }
    s[i] = '\0';
    if (c != EOF) {
        line_i--;
    }
    return NUMBER;
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
