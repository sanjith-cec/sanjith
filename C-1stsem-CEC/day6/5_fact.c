#include<stdio.h>
int main(){
    int num=0, res = 1;
    printf("Enter a number: ");
    scanf("%d",&num);// 5! --> 5*4*3*2*1 = 120
    while(num>=1){ //0>=1
        res = res * num; //120
        num--; //0
    }
    printf("Factorial is : %d \n",res);
}