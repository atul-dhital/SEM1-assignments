#include <stdio.h>
void main()
{
    int a, b, c, d, e,f;
    printf("please enter numbers for Logical And");
    printf("Enter the value of first number:\n");
    scanf("%d", &a);
    printf("Enter the value of 2nd number:\n");
    scanf("%d", &b);
    printf("please enter numbers for Logical OR");
    printf("Enter the value of first number:\n");
    scanf("%d", &c);
    printf("Enter the value of 2nd number:\n");
    scanf("%d", &d);

    printf("please enter numbers for Logical NOT");
    printf("Enter the value of first number:\n");
    scanf("%d", &e);
    printf("Enter the value of 2nd number:\n");
    scanf("%d", &f);
    printf("The reaslt of AND operatort is %d\n", (a > b) && (b > a));
    printf("The reaslt of OR operatort is %d\n", (c > d) || (d > c));
    printf("The reaslt of NOT operatort is %d\n", !(a > b));
}