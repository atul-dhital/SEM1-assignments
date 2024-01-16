#include <stdio.h>

// for loop
//  int main(){
//      int a = 10;
//      for(int i=1; i<=5;i++){
//          printf("A[%d] = %d\n",i,a);
//      }
//  }

// to create multiplaction table of entred number
// int main()
// {
//     int num;
//     printf("Enter the Number : ");
//     scanf("%d",&num);
//     // using for loop
//     for (int i = 1; i <= 10 ; i++) {
//         printf("%d * %d = %d \n",num,i,num*i);
//         }
//     return 0;
// }

// odd and even number list from user input
//  int main(){
//      int n,i;
//      printf("Enter the range:");
//      scanf("%d",&n);
//      printf("\nOdd numbers are:\n");
//      for(i=1;i<=n;i+=2){
//          printf("%d\t",i);
//      }
//      printf("\nEven numbers are:\n");
//      for(i=2;i<=n;i+=2)
//      {
//          printf("%d\t",i);
//      }

// }

// sum of odd even till user input

// int main()
// {
//     int a, sum_even = 0, sum_odd = 0;
//     printf("Enter a number: ");
//     scanf("%d", &a);
//     // for even  using loop

//     for (int i = 1; i <= a; i++)
//     {
//         if (i % 2 == 0)
//         {
//             sum_even = sum_even + i;
//         }
//         else
//         {
//             sum_odd = sum_odd + i;
//         }
//     }
//     printf("even sum from 0 to %d is %d\n", a, sum_even);
//     printf("even sum from 0 to %d is %d\n", a, sum_odd);
// }

//wap in c to find 50 to 100 hundred
//wap to find out the  factrioal of the number given by the user

// int main(){
//     int n,fact=1,c;
//     printf("Enter any positive integer : ");
//     scanf("%d",&n);
//     printf("Factorial of %d is: ",n);
//     c=n;
//     while(c!=0)
//     {
//         fact=fact*c;
//         c--;
//         }
//         printf("%d",fact);
// }


//count of odd and even to the user input number
// int main(){
//     int n,i,count_even=0,count_odd=0;
//     printf("Enter a number: ");
//     scanf("%d", &n);
//     for(i=1;i<=n;i++)
//     {
//         if(i%2==0)
//         {
//             count_even++;
//         }
//         else            
//         {
//             count_odd++;    
//         }
//     }
//     printf("Even count is %d\n",count_even);
//     printf("Odd count is %d\n",count_odd);
//     return 0;
// }

//wap to find out the  factrioal of the number given by the user
int main(){
    unsigned long int fact=1,c; //the unsigned  is used for to unassign the sign bit and log refers to data type thas hold 8bit intiger
    printf("Enter any positive integer : ");
    scanf("%d",&c);
    
    for(c;c!=1;c--){
        fact=fact*c;
      
    }
    // while(c!=0)
    // {
    //     fact=fact*c;
    //     c--;
    //     }
        printf("%ld",fact);
    return 0;
}