#include<stdio.h>
int main(){
    int a = 10;
    int *ptr = &a;
    printf("Value of a: %d\n",a);
    printf("Address of a: %p \n",&a);
    printf("Value of ptr: %p \n",ptr);
    printf("Address of ptr: %p \n",&ptr);
}