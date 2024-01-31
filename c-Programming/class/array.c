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
int main(){
    int a[10];
    int i;
    int search;
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the number to search");
    scanf("%d",&search);
    for(i=0;i<10;i++){
        if(a[i]==search){
            printf("number found at %d position",i);
        }
    }
    return 0;
}
