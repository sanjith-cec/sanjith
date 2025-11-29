#include<stdio.h>
int main(){
    int n, sum =0;
    printf("Enter a number: ");
    scanf("%d",&n);//5 -->15
    // int i = 1;
    // while(i<=n){
    //     sum+=i; //sum=sum+i;
    //     i++;
    // }
    sum = (n*(n+1))/2; //5*6 ==> 30/2 =15
    printf("Sum is: %d",sum);
}