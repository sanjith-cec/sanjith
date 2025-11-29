#include<stdio.h>
int main(){
    int num = 100;
    int *ptr = &num;
    printf("Value of num: %d\n",num);
    printf("Value of num using ptr: %d\n",*ptr);//*1000 -> 100
    printf("Value of ptr: %p\n",ptr);
    printf("Value of ptr using num: %p",&num);
}