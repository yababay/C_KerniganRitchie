#include <stdio.h>

#define swap(t,x,y) { t temp = x; x = y; y = temp; }

int main() {
    int x = 3, y = 4;
    double a = 3.14, b=-44.0;

    printf("Before swapping: x=%d, y=%d\n", x, y);
    swap(int, x, y);
    printf("After swapping: x=%d, y=%d\n", x, y);

    printf("Before swapping: a=%g, b=%g\n", a, b);
    swap(double, a, b);
    printf("After swapping: a=%g, b=%g\n", a, b);

    return 0;
}
