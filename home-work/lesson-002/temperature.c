#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 450;
    step = 50;

    fahr = lower;
    printf("\nTemperature from %d to %d.\n", lower, upper);
    printf("--------------------------------------------\n");
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0) ;
        printf("Fahrenheit: %3.0f,\tCelsius: %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    printf("--------------------------------------------\n");
}