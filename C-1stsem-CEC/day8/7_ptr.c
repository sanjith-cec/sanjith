#include<stdio.h>
int main(){
    int a = 10;
    int b = 20;
    printf("Borfore swapping:\n");
    printf("a: %d \n",a);
    printf("b: %d\n",b);
    int temp = a;
    a = b;
    b = temp;
    printf("After swapping:\n");
    printf("a: %d \n",a);
    printf("b: %d \n",b);
}