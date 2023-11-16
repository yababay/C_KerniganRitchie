#include <stdio.h>

// test case:
// echo '   a b    c d   ef  ' | ./exercise_1.9
// result:
// ' a b c d ef '
int main() {
    int c, blank_flag = 0;

    while((c = getchar()) != EOF) {
        if(c == ' ') {
            if (!blank_flag) {
                blank_flag = 1;
                putchar(c);
            }
        }
        else {
            blank_flag = 0;
            putchar(c);
        }
    }
    return 0;
}
