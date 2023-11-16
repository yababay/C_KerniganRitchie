#include <stdio.h>

// test case:
// echo -en 'He Hi Ho\tHa\nHe-he He \n' | ./exercise_1_8
// result:
// Blanks: 4    Tabs: 1 Newlines: 2
int main() {
    int c;
    int b_count = 0, t_count = 0, nl_count = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++b_count;
        }
        else if (c == '\t') {
            ++t_count;
        }
        else if (c == '\n') {
            ++nl_count;
        }
    }
    printf("Blanks: %d\tTabs: %d\tNewlines: %d\n", b_count, t_count, nl_count);
    return 0;
}
