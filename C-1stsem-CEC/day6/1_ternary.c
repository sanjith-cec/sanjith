#include<stdio.h>
int main(){
    int a = 60;
    int b = 40;
    if(a>b){
        printf("a is: %d \n",a);
    }else{
        printf("b is: %d \n",b);
    }
    (a>b)?printf("a is: %d \n",a) : printf("b is: %d \n",b);
}