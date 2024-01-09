#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num1, num2;
    char choice;
    float result;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter your choice (+, -, *, /): ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Error: division by 0\n");
            return 1;
        }
        else
        {
            result = (float)num1 / num2; // for accurate division
        }
        break;
    default:
        printf("Invalid choice\n");
        return 1;
    }

    printf("Result: %.2f\n", result); // floating-point number with 2 decimal places

    return 0;
}
