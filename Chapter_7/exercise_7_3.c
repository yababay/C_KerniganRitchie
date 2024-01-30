#include <stdio.h>
#include <stdarg.h>

void minprintf(char *, ...);

int main() {
    minprintf("%d\t%i\t%o\t%x\t%X\t%u\t%c\n", 95, 95, 95, 95, 95, 95, 95);
    minprintf("%s\n", "Hello, world!");
    minprintf("%f\t%e\t%E\t%g\t%G\n", 386.6938, 386.6938, 386.6938, 386.6938,
            386.6938);
    minprintf("Over 95% of people can read, \
literacy is a skill for over 50%. That's statistics\n");

    return 0;
}

void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    unsigned uval;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch(*++p) {
            case 'd':
            case 'i':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'o':
                ival = va_arg(ap, int);
                printf("%o", ival);
                break;
            case 'x':
            case 'X':
                ival = va_arg(ap, int);
                printf("%x", ival);
                break;
            case 'u':
                uval = va_arg(ap, unsigned);
                printf("%u", uval);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 'e':
            case 'E':
                dval = va_arg(ap, double);
                printf("%e", dval);
                break;
            case 'g':
            case 'G':
                dval = va_arg(ap, double);
                printf("%g", dval);
                break;
            case 'c':
                ival = va_arg(ap, int);
                printf("%c", ival);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++) {
                    putchar(*sval);
                }
                break;
            default:
                putchar('%');
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}
