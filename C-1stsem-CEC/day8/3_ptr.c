#include<stdio.h>
int main(){
    int a = 20;
    int *ptr = &a;
    printf("Before Changing value of a: %d \n",a);
    *ptr=80;
    printf("After Changing value of a: %d \n",a);
    (*ptr)++;
    printf("After Changing value of a: %d \n",a);
}