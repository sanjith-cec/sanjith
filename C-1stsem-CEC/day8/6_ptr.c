#include<stdio.h>
int main(){
    int arr[3] = {100,200,300};
    int *ptr = arr;
    printf("address of arr[0]: %p \n",&arr[0]);
    printf("address of arr: %p \n",arr);
    printf("address of arr using pointer: %p \n",ptr);
    printf("address of arr[1]: %p \n",&arr[1]);
    printf("address of arr[2] using pointer: %p \n",ptr+2);
}