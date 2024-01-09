#include <stdio.h>
void main()
{
    int x, y, z;
    // get value of x
    printf("Enter the value of x:");
    scanf("%d", &x);
    // pre-increment
    y = ++x;
    printf("post increment of x is:%d", y);
    // post increment
    z = x++;
    printf("post increment of x is:%d", z);    
    getch();
}                                                                 