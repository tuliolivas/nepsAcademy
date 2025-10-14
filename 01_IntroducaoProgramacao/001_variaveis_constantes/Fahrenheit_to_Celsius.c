#include <stdio.h>

int main() {
    /*
    This program converts a temperature from Fahrenheit to Celsius.
    The formula used is: C = (F - 32) * 5/9
    */

    float fahrenheit, celsius;

    printf("Enter temperature in Fahrenheit: ");
    
    if (scanf("%f", &fahrenheit) != 1) {
        fprintf(stderr, "Invalid input. Please enter a numeric value.\n");
        return 0;
    }

    celsius = (fahrenheit - 32.0) * (5.0 / 9.0);

    printf("Temperature in Celsius: %.2f\n", celsius);

    return 0;
}
