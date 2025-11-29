// 989 -> 3
#include <stdio.h>
int main(){
    int num, duplicate, reverse=0, digit=0;
    printf("Enter a number: ");
    scanf("%d",&num); 
    duplicate = num;
    while(num!=0){ 
        digit = num %10;
        reverse = reverse*10+digit; 
        num = num/10; //num/=10;
    }
    if(duplicate == reverse){
        printf("Palindrome number \n");
    }else{
        printf("Not a palindrome number \n");
    }

    int a = 10;
    int b = 20;
    a=a+b; // 10+20 = 30 
    a+=b;// a=a+b;
    a*=b; // a=a*b;
    a-=b; // a=a-b;
    a/=b; // a=a/b;

}