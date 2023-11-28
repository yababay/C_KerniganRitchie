#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int v[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("%d\t%d\n", binsearch(8, v, 10), binsearch(10, v, 10));
    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high)/2;
        if (x <= v[mid]) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return (x == v[low]) ? low : -1;
}
