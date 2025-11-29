#include<stdio.h>
void mul(int a, int b);
int main(){
    mul(10,20);
    mul(2,2);
}

void mul(int a,int b){
    printf("Multiplication is: %d\n",a*b);
}