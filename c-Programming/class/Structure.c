#include <stdio.h>  

struct student 
{
    char name[20]; 
    int roll;      
    float marks;   
} ;

int main() 
{
int n;
    struct student students[10];
    printf("Please Enter the number of student");
    scanf("%d", &n);
    printf("Enter the following details of students:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("\n===========================================\n");
        printf("Student %d:\n", i + 1);
        printf("Name: "); 
        scanf("%s", students[i].name); 
        printf("Roll number: "); 
        scanf("%d", &students[i].roll); 
        printf("Marks: "); 
        scanf("%f", &students[i].marks);
        printf("\n===========================================\n"); 
    }

    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name); 
        printf("Roll number: %d\n", students[i].roll); 
        printf("Marks: %.2f\n", students[i].marks); 
        printf("\n===========================================");
    }
        return 0; 
}