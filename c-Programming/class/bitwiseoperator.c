#include<stdio.h>
//bit wise operators
// void main(){
//     int a =100;  //1100100
//     int b=300; //100101100
//     int tesAnd=a & b;
//     int tesExc= a^b;
//     int c = ~ a;
//     printf("the bitwise operator %d & %d is %d\n", a, b,tesAnd);
//     printf("the bitwise operator %d ^ %d is %d\n", a, b,tesExc);
//     printf("the bitwise operator %d ~ %d is %d", a, b,c);
// }
//bitwise shitft
void main(){
    int a = 8,b; //1000
    b = a>>2;
    printf("bitwie left shit of %d was:%d",a,b);
}