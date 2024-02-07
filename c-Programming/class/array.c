#include<stdio.h>
// arrey
// int  main(){
//     int a[10];
//     int i;
//     for(i=0;i<10;i++){
//         scanf("%d",&a[i]);
//     }
//     for(i=0;i<10;i++){
//         printf("%d",a[i]);
//     }
//     return 0;
// }
//sum of event
// int main(){
//     int a[10];
//     int i;
//     int sum=0;
//     for(i=0;i<10;i++){
//         scanf("%d",&a[i]);
//     }
//     for(i=0;i<10;i++){
//         sum=sum+a[i];
//     }
//     printf("%d",sum);
//     return 0;
// }


// wap to display larger and smaller number of array
// int main(){
//     int a[10];
//     int i;
//     int large=0;
//     int small=0;
//     for(i=0;i<10;i++){
//         scanf("%d",&a[i]);
//     }
//     for(i=0;i<10;i++){
//         if(a[i]>large){
//             large=a[i];
//         }
//         if(a[i]<small){
//             small=a[i];
//         }
//     }
// }

//search inside array 
// int main(){
//     int a[10];
//     int i;
//     int search;
//     for(i=0;i<10;i++){
//         scanf("%d",&a[i]);
//     }
//     printf("enter the number to search");
//     scanf("%d",&search);
//     for(i=0;i<10;i++){
//         if(a[i]==search){
//             printf("number found at %d position",i);
//         }
//     }
//     return 0;
// }


// exaple of 2-d array
// int main(){
//     int a[10][10];
//     int i,j;
//     for(i=0;i<10;i++){
//         for(j=0;j<10;j++){
//             scanf("%d",&a[i][j]);
//         }
//     }
//     for(i=0;i<10;i++){
//         for(j=0;j<10;j++){
//             printf("%d",a[i][j]);
//         }
//     }
// }
// transpose of matrix
// #include <stdio.h>
// void transpose(int m, int n, int a[][n]) {
//     int i, j;
//     for (i = 0; i < m; i++) {
//         for (j = i; j < n; j++) {
//             // Swap elements a[i][j] and a[j][i]
//             int temp = a[i][j];
//             a[i][j] = a[j][i];
//             a[j][i] = temp;
//         }
//     }
// }

//sum of 2d array
// int main(){
//     int a[10][10];
//     int i,j;
//     int sum=0;
//     for(i=0;i<10;i++){
//         for(j=0;j<10;j++){
//             scanf("%d",&a[i][j]);
//         }
//         //add the array
//         sum+=a[i][9-i];
//     }
//     printf("%d",sum);
// }



//transpose the value of array
