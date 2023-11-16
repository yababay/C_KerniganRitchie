#include <stdio.h>

#define IN  1
#define OUT 0

/* test case:
 * echo -en 'Hello,\tworld!\nThis is my  program' | ./exercise_1_12
 * result:
 * Hello,
 * world!
 * This
 * is
 * my
 * program
 */
int main() {
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                state = OUT;
                putchar('\n');
            }
        }
        else {
            state = IN;
            putchar(c);
        }
    }
    printf("\n");
    return 0;
}
