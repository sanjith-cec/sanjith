#include<stdio.h>
#include<string.h>
int main(){
    char user_input[100];
    printf("Enter a String: ");
    fgets(user_input,100,stdin);
    printf("Entered String is: %s",user_input);
}