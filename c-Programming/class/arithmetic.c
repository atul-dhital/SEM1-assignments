#include <stdio.h>
void main()
{
    int a,b, c,d,e;
    printf("Enter the value of first number:\n");
    scanf("%d",&a);
    printf("Enter the value of 2nd number:\n");
    scanf("%d",&b);
    c = a + b;
    d=a*b;
    e=a-b;
    a*=b;
    printf("The sum of given two number is:%d\n", c);
    printf("The sub of given two number is:%d\n", e); 
    printf("The mul of given two number is:%d\n", d);
    printf("The mul of given two number is:%d\n", a);
}