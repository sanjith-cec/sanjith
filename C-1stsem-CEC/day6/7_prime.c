#include<stdio.h>
int main(){
    int num =0;
    printf("Enter a number: ");
    scanf("%d",&num);//10
    int isPrime = 1;
    if(num<=1){
        isPrime=0;
    }
    for(int i=2;i<=num/2;i++){
        if(num%i==0){//10%2==0
            isPrime = 0;
            break;// to exit the loop
        }
    }
    if(isPrime==1){
        printf("It is a Prime Number");
    }else{
        printf("Not a Prime Number");
    }

}