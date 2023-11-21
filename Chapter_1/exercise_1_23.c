#include <stdio.h>

#define TRUE 1 /* true boolean value */
#define FALSE 0 /* false boolean value */

/* main function */
int main() {
    /* variables:
     * in_comment: is current character is inside the comment
     * about_to: if we are about to enter or leave comment block
     * c: current symbol
     */
    int in_comment, about_to;
    char c;

    in_comment = about_to = FALSE;
    while ((c = getchar()) != EOF) {
        if (in_comment) {
            if (about_to) {
                if (c == '/') {
                    in_comment = FALSE;
                }
                about_to = FALSE;
            }
            else if (c == '*') {
                about_to = TRUE;
            }
        }
        else {
            if (about_to) {
                if (c == '*') {
                    in_comment = TRUE;
                }
                else {
                    putchar('/');
                    putchar(c);
                }
                about_to = FALSE;
            }
            else if (c == '/') {
                about_to = TRUE;
            }
            else {
                putchar(c);
            }
        }
    }

    printf("Done!\n");
    return 0;
}

/* testing:
 * cat exercise_1_23.c | ./exercise_1_23
 */
