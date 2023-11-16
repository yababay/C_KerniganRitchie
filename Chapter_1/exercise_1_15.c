#include <stdio.h>

#define LOWER 0.0
#define UPPER 300.0
#define STEP 20.0

float ftoc(float fahr);

int main() {
    float fahr, celsius;
    
    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = ftoc(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += STEP;
    }
    return 0;
}

float ftoc(float fahr) {
    float celsius;
    celsius = (5.0/9.0) * (fahr-32.0);
    return celsius;
}
