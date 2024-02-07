#include<stdio.h>

//functions
// int main(){
//     int a,b,sum;
//     printf("enter two numbers");
//     scanf("%d%d",&a,&b);
//     return 0;
// }
// int add(int a, int b){
//     return a+b;
// }

//functions having parameterand having value
int main(){
    int a,b,sum;
    printf("enter two numbers");
    scanf("%d",&a);
    printf("another number");
    
    scanf("%d",&b);
    sum=add(a,b);
    printf("sum is :%d",sum);
    return 0;
}
int add(int a, int b){
    return a+b;
}

