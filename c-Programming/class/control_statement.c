#include <stdio.h>
// contrtol Statement is  those types of statement which control the
//  flow of program i.e if conditions

// example of if  else condition
//
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

// if elseif (we can use as needed)

// int main()
// {
//     int num1, num2, num3;
//     printf("Please enter First number:");
//     scanf("%d", &num1);
//     printf("Please enter 2nd number:");
//     scanf("%d", &num2);
//     printf("Please enter 3rd number:");
//     scanf("%d", &num3);
//     if (num1 >= num2 && num1 >= num3)
//     {
//         printf("\n%d is greater than both %d and %d ", num1, num2, num3);
//     }
//     else if (num2 >= num3 && num2 >= num1)
//     {
//         printf("\n%d is greater than both %d and %d ", num2, num1, num3);
//     }
//     else
//     {
//         printf("\n%d is greater than both %d and %d ", num3, num1, num2);
//     }
// }
// wap in c to check weather the user is voter or not
// int main(){
//     int age;
//     printf("Please enter your age:");
//     scanf("%d",&age);
//     if (age>=18)
//     {
//         printf("you can vote");
//     }
//     else{
//         print("You cant vote");
//     }
//     return 0;

// }

// nested if else

// int main()
// {
// int number;
// printf("Enter a number: ");
// scanf("%d",&number);

//     if (number > 0)
//     {
//         printf("The number is positive.");
//     }

//     else
//     {
//         if (number < 0)
//         {
//             printf("The number is negative.");
//         }

//         else
//         {
//             printf("The number is zero.");
//         }
//     }
// }

// switch case
//  int main()
//  {
//      int num1, num2;
//      char choice;
//      float result;
//      printf("Enter first number: ");
//      scanf("%d", &num1);
//      printf("Enter second number: ");
//      scanf("%d", &num2);
//      printf("Enter your choice (+, -, *, /): ");
//      scanf(" %c", &choice);

//     switch (choice)
//     {
//     case '+':
//         result = num1 + num2;
//         break;
//     case '-':
//         result = num1 - num2;
//         break;
//     case '*':
//         result = num1 * num2;
//         break;
//     case '/':
//         if (num2 == 0)
//         {
//             printf("Error: division by 0\n");
//             return 1;
//         }
//         else
//         {
//             result = (float)num1 / num2; // for accurate division
//         }
//         break;
//     default:
//         printf("Invalid choice\n");
//         return 1;
//     }

//     printf("Result: %.2f\n", result); // floating-point number with 2 decimal places

//     return 0;
// }

// marksheet

// int main()
// {
//     float sub1, sub2, sub3, sub4, sub5, sum, peer;
//     printf("Please enter sub1 subject:");
//     scanf("%f", &sub1);
//     printf("Please enter sub1 subject:");
//     scanf("%f", &sub2);
//     printf("Please enter sub1 subject:");
//     scanf("%f", &sub3);
//     printf("Please enter sub1 subject:");
//     scanf("%f", &sub4);
//     printf("Please enter sub1 subject:");
//     scanf("%f", &sub5);
//     sum = sub1 + sub2 + sub3 + sub4 + sub5;
//     peer = sum * 100 / 500;
//     if (peer <= 40)
//     {
//         printf("\n%f is your  total mark \n %f % is yor percentage and you socred A- ", sum, peer);
//     }
//     else if (peer <= 80)
//     {
//         printf("\n%f is your  total mark \n %f % is yor percentage and you socred A ", sum, peer);
//     }
//     else
//     {
//         printf("\n%f is your  total mark \n %f % is yor percentage and you socred A+ ", sum, peer);
//     }
//return 0;
// }

//wap to swap the number of 2 variable
// int main() {
//     int a = 10;
//     int b = 20;

//     // Print the original values of a and b
//     printf("Before swapping: a = %d, b = %d\n", a, b);

//     // Swap the values of a and b
//     int temp = a;
//     a = b;
//     b = temp;

//     // Print the swapped values of a and b
//     printf("After swapping: a = %d, b = %d\n", a, b);

//     return 0;
// }
// ANOTHER 

// int main() {
//     int a = 4;
//     int b = 2;

//     printf("Before swapping, a = %d, b = %d\n", a, b);

//     swap(&a, &b);

//     printf("After swapping, a = %d, b = %d\n", a, b);

//     return 0;
// }

// wap to swap the number of 2 variable with out using 3rd variable

// int main() {
//     int a = 5;
//     int b = 10;

//     // Swap the values of a and b using the XOR operator
//     a = a ^ b;
//     b = a ^ b;
//     a = a ^ b;

//     // Print the swapped values of a and b
//     printf("a = %d\n", a);
//     printf("b = %d\n", b);

//     return 0;
// }
