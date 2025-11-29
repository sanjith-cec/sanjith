#include<stdio.h>
int main(){
    int a= 10;
    int *ptr = &a;
    int **ptr2 = &ptr;
    int ***ptr3 = &ptr2;

    printf("Value of a using ptr2: %d \n",**ptr2);
    printf("Value of a using ptr3: %d \n",***ptr3);
    printf("Value of a using ptr3: %d \n",*(*(*(*(&ptr3)))));
}