#include<stdio.h>

void main() {
int x=5;
static int y = 10;
auto int z=10;
 x = x+1;
 y = y+1;
 z= z+1;

  printf("Result %d\n ", x); 
  printf("Result: %d \n", y); 
  printf("Result: %d \n", z); 
 
}
