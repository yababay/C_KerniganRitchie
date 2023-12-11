#include <stdio.h>
#include <ctype.h>

int main() {
    double atof(char[]);

    printf("%g\n", atof("134.45"));
    printf("%g\n", atof("  0"));
    printf("%g\n", atof("-13423"));
    printf("%g\n", atof("-123.45e-6"));
    printf("%g\n", atof("346.6E2"));
    printf("%g\n", atof("346.6E-0"));

    return 0;
}

double atof(char s[]) {
    double val, power;
    int i, sign, exp, exp_sign;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }

        for (exp = 0; isdigit(s[i]); i++) {
            exp = 10 * exp + (s[i] - '0');
        }
        for (; exp > 0; exp--) {
            power = (exp_sign > 0) ? power / 10 : power * 10;
        }
    }

    return sign * val / power;
}
