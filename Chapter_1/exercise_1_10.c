#include <stdio.h>

/*
 * test case:
 * echo -en 'Hello,\tusername!\b. Backslashes:\\ and \\' | ./exercise_1_10
 * result:
 * Hello,\tusername!\b.Backslashes:\\ and \\
 */

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b') {
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        }
        else {
            putchar(c);
        }
    }
    printf("\n");
    return 0;
}
