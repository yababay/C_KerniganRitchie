#include <stdio.h>
#include <stdarg.h>

#define MAXLEN 100

void minscanf(char *, ...);

int main() {
    int i;
    char c;
    float d;
    char s[MAXLEN];

    minscanf("%d;%c;%f;%s", &i, &c, &d, s);
    printf("%d\n", i);
    printf("%c\n", c);
    printf("%f\n", d);
    printf("%s\n", s);

    return 0;
}

void minscanf(char *fmt, ...) {
    va_list ap;
    char *p, *sval, tmp;
    int *ival;
    float *dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            scanf("%c", &tmp);
            continue;
        }

        switch(*++p) {
            case 'd':
            case 'i':
                ival = va_arg(ap, int *);
                scanf("%d", ival);
                break;
            case 'o':
                ival = va_arg(ap, int *);
                scanf("%o", ival);
                break;
            case 'x':
                ival = va_arg(ap, int *);
                scanf("%x", ival);
                break;
            case 'f':
                dval = va_arg(ap, float *);
                scanf("%f", dval);
                break;
            case 'e':
                dval = va_arg(ap, float *);
                scanf("%e", dval);
                break;
            case 'g':
                dval = va_arg(ap, float *);
                scanf("%g", dval);
                break;
            case 'c':
                sval = va_arg(ap, char *);
                scanf("%c", sval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf("%s", sval);
                break;
            default:
                scanf(";");
                sprintf(sval, "%c", *p);
                scanf(sval, &tmp);
                break;
        }
    }
    va_end(ap);
}
