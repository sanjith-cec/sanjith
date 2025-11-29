#include<stdio.h>
//function prototype
int add(int num1, int num2);
int sub(int num1, int num2);
int main(){
    int res1=add(4,5);
    int res2=add(10,20);
    int res3=add(30,40);
    int res4=add(50,90);
    printf("res1: %d\n",res1);
    printf("res2: %d\n",res2);
    printf("res3: %d\n",res3);
    printf("res4: %d\n",res4);
    int res5 = sub(40,20);
    printf("res5: %d\n",res5);
}

int add(int num1, int num2){
   return num1+num2;
}

int sub(int num1, int num2){
    return num1-num2;
}