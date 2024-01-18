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
// int main(){
//     unsigned long int fact=1,c; //the unsigned  is used for to unassign the sign bit and log refers to data type thas hold 8bit intiger
//     printf("Enter any positive integer : ");
//     scanf("%d",&c);
    
//     for(c;c!=1;c--){
//         fact=fact*c;
      
//     }
//     // while(c!=0)
//     // {
//     //     fact=fact*c;
//     //     c--;
//     //     }
//         printf("%ld",fact);
//     return 0;
// }

//


///sum of entred number digits 

// int main(){
//     int num,rem, count=0,sum=0;
//     printf("Enter a number: ");
//     scanf("%d",&num);
//     for(;num!=0;num=num/10) 
//     {
//         rem=num%10;
//         sum=sum+rem;
//         count++;
//     }
//     printf("The sum of the digits of the number is %d",sum);
//     printf("\nThe number of digits of the number is %d",count);
//     return 0;
// }

//sum of entered number even digit 


// int main() {
//     int num, rem, count = 0, sum = 0, even = 0, odd = 0;

//     printf("Enter a number: ");
//     scanf("%d", &num);

//     for (; num != 0; num = num / 10) {
//         rem = num % 10;
//         sum = sum + rem;

//         if (rem % 2 == 0) { //checking the digit is odd or even
//             even = even + rem;
//         } else {
//             odd = odd + rem;
//         }

//         count++;
//     }

//     printf("The sum of the digits of the number is %d\n", sum);
//     printf("The number of digits of the number is %d\n", count);
//     printf("The sum of even digits of the number is %d\n", even);
//     printf("The sum of odd digits of the number is %d\n", odd);

//     return 0;
// }


//armstorong number

int main() {
    long n, temp, sum = 0, rem;

    printf("Enter a number : \n");
    scanf("%ld", &n);

    temp = n;

  for (; temp != 0; temp /= 10) {
    rem = temp % 10;   
    sum += rem * rem * rem;  
}


    if (sum == n) {
        printf("\n The Number is an Armstrong Number.\n");
    } else {
        printf("\n The Number is not an Armstrong Number.\n");
    }

    return 0;
}