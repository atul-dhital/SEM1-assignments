#include <stdio.h>

// question1
//  void main(){
//      printf{"Hello World!\n"};
//      getch()
//  }

// question 2 ,3
//  void main(){
//      int num;
//      printf("please enter a number");
//      scanf("%d",num);
//      printf("%d is your number",num);

// }

// question 4 addition

// void main(){
//     float num1 , num2, sum;
//     printf("Enter the first number: ");
//     scanf("%f", &num1);
//     printf("\nEnter the second number: ");
//     scanf("%f",&num2);
//     sum = num1 + num2 ;
//     printf("\nThe sum of %0.2f and %0.2f is :%0.2f\n",num1,num2,sum);
// }

// area of circle qn6
//  void main(){
//      float r, area;
//      printf("Please Enter the Radius of Circle: \n");
//      scanf("%f", &r);
//      area=3.14*r*r;
//      printf("Area of circle is:%0.2f",area);
//      scanf ("%.2f is the area of circul having area of %f",area, r);

// }

// question7
// int main()
// {
//     float sub1, sub2, sub3, sub4, sub5, total, per;
//     printf("Enter Marks in Subject 1:\n");
//     scanf("%f", sub1);
//     printf("Enter Marks in Subject 2:\n");
//     scanf("%f", sub2);
//     printf("Enter Marks in Subject 3:\n");
//     scanf("%f", sub3);
//     printf("Enter Marks in Subject 4:\n");
//     scanf("%f", sub4);
//     printf("Enter Marks in Subject 5:\n");
//     scanf("%f", sub5);
//     total=sub1 + sub2+ sub3+ sub4+ sub5;
//     per=(total/5);
//     printf("Total Marks=%0.2f\n",total);
//     printf("The percentage you scored is %.2f", per);
// return 0;
// }

// gcd of two numbers

/// odd even
// int main(){
//     int num;
//     printf("Please enteer the number:");
//     scanf("%d",&num);
//     if (num%2==0)
//     {
//         printf("%d is  Even",num);
//     }
//     else{
//         printf(" %d is odd",num);
//     }
//     return 0;

//}

int main()
{
    int days;
    printf("How many days are there in a year?\n");
    scanf("%d", &days);
    if (days == 366)
    {
        printf("It's a leap year!\n");
    }
    elseif(days==365)
    {
        printf("It's not a leap year!");
    }
    else{
        printf("wrong input");
    }
    return 0;
}

//Largest number in two

// int main(){
//     int num1, num2 ;
//     printf("Enter first number : ");
//     scanf("%d", &num1);
//     printf("\nEnter second number : ");
//     scanf("%d", &num2);
//     if (num1 > num2){
//         printf("%d is latger than %d",num1,num2);
//     }
//     else{
//         printf("%d is latger than %d",num2,num1);
//     }
//     return 0;
// }


//Accept 3 numbers from user and print largest number. (for all possible inputs)

// int main(){
//     int a , b , c ;
//     printf("Enter the three numbers: \n");
//     scanf("%d%d%d" , &a , &b , &c );
//     if ((a >= b && a >= c))
//     printf("%d is the largest number" , a);
// }