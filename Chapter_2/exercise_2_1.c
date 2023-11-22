#include <stdio.h>
#include <limits.h>

int main() {
    printf("signed char:\n");
    printf("max(library): %d\n", SCHAR_MAX);
    printf("max(calculated): %d\n", (char)((unsigned char)~0 >> 1));
    printf("min(library): %d\n", SCHAR_MIN);
    printf("min(calculated): %d\n", -(char)((unsigned char)~0 >> 1) - 1);

    printf("unsigned char:\n");
    printf("max(library): %d\n", UCHAR_MAX);
    printf("max(calculated): %d\n", (unsigned char)~0);
    printf("min(library): %d\n", 0);
    printf("min(calculated): %d\n", 0);
    
    printf("signed short:\n");
    printf("max(library): %d\n", SHRT_MAX);
    printf("max(calculated): %d\n", (short)((unsigned short)~0 >> 1));
    printf("min(library): %d\n", SHRT_MIN);
    printf("min(calculated): %d\n", -(short)((unsigned short)~0 >> 1) - 1);

    printf("unsigned short:\n");
    printf("max(library): %d\n", USHRT_MAX);
    printf("max(calculated): %d\n", (unsigned short)~0);
    printf("min(library): %d\n", 0);
    printf("min(calculated): %d\n", 0);

    printf("signed int:\n");
    printf("max(library): %d\n", INT_MAX);
    printf("max(calculated): %d\n", (int)((unsigned int)~0 >> 1));
    printf("min(library): %d\n", INT_MIN);
    printf("min(calculated): %d\n", -(int)((unsigned int)~0 >> 1) - 1);
    
    printf("unsigned int:\n");
    printf("max(library): %d\n", UINT_MAX);
    printf("max(calculated): %d\n", (unsigned int)~0);
    printf("min(library): %d\n", 0);
    printf("min(calculated): %d\n", 0);

    printf("signed long:\n");
    printf("max(library): %ld\n", LONG_MAX);
    printf("max(calculated): %ld\n", (long)((unsigned long)~0 >> 1));
    printf("min(library): %ld\n", LONG_MIN);
    printf("min(calculated): %ld\n", -(long)((unsigned long)~0 >> 1) - 1);
    
    printf("unsigned long:\n");
    printf("max(library): %ld\n", ULONG_MAX);
    printf("max(calculated): %ld\n", (unsigned long)~0);
    printf("min(library): %ld\n", 0l);
    printf("min(calculated): %ld\n", 0l);
}
