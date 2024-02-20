#include <stdio.h>
#include <stdlib.h>

void *calloc_c(int, int);

int main() {
    double *a;

    a = calloc_c(5, sizeof(double));
    printf("%f\n", a[3]);

    *(a+3) = 4.5;
    printf("%f\n", a[3]);

    return 0;
}

void *calloc_c(int n, int size) {
    int *p;
    int i, ns = n * size;

    if ((p = malloc(ns)) == NULL) {
        fprintf(stderr, "calloc_c: unable to allocate memory\n");
        return NULL;
    }

    for (i = 0; i < ns; i += sizeof(int)) {
        *(p+i) = 0;
    }

    return p;
}
