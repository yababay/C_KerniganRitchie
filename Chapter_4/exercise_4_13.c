#include <stdio.h>

void reverse(char s[]);
static void reverse_r(char s[], int l, int r);

int main() {
    char s1[] = "Hello, world!";
    char s2[] = "TestString\tBye\nBye-bye!";

    reverse(s1);
    printf("%s\n", s1);

    reverse(s2);
    printf("%s\n", s2);

    return 0;
}

void reverse(char s[]) {
    int right;

    for (right = 0; s[right] != '\0'; right++)
        ;

    reverse_r(s, 0, right-1);
}

void reverse_r(char s[], int l, int r) {
    int temp;

    if (l < r) {
        temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        reverse_r(s, ++l, --r);
    }
}
