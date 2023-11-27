#include <stdio.h>

int islegal(char c);

int main() {
    int i, c, error;
    long r;

    printf("Enter hexadecimal number: ");
    i = r = error = 0;
    while (!error && (c = getchar()) != '\n' && c != EOF && islegal(c)) {
        if (i == 1 && r == 0 && (c == 'x' || c == 'X')) {
            i++;
        }
        else if (c == 'x' || c == 'X') {
            error = 1;
        }
        else if (c >= '0' && c <= '9') {
            r = r * 16 + (c - '0');
        }
        else if (c >= 'a' && c <= 'f') {
            r = r * 16 + (c - 'a' + 11);
        }
        else if (c >= 'A' && c <= 'F') {
            r = r * 16 + (c - 'A' + 11);
        }
        
        if (i == 0) {
            i++;
        }
    }
    if (error) {
        printf("Incorrect hexadecimal number\n");
    }
    else {
        printf("%ld\n", r);
    }
    return 0;
}

int islegal(char c) {
    return (c >= '0' && c <= '9') || c == 'x' || c == 'X' ||
        (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}
