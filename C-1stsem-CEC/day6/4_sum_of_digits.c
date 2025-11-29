// 989 -> 3
#include <stdio.h>
int main(){
    int num, sum=0, digit;
    printf("Enter a number: ");
    scanf("%d",&num); //123
    while(num!=0){ 
        digit = num %10; //3
        sum = sum + digit; //sum+=digit;
        num = num/10;
    }
    printf("Sum of digits is : %d \n",sum);
}