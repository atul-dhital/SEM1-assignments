#include <stdio.h>
#include <math.h>
int main() {
    // Get the number whose square root we want to find
    float a;
    printf("Enter a number: ");
    scanf("%f", &a);

    // Initialize the guess for the square root
    float x = a / 2;

    // Iterate until the guess is close enough to the actual square root
    while (fabs(x * x - a) > 0.0001) {
        // Calculate the next guess using the Babylonian method
        x = (x + a / x) / 2;
    }

    // Print the square root
    printf("The square root of %.0f is %.2f\n", a, x);

    return 0;
}