#include<stdio.h>
#include<string.h>
int main(){
    char first_name[]="pavan";
    char last_name[]="gowda";
    char another_name[] = "pavan";
    char other_name[] = "pavan";

    printf("length of first_name: %d \n",strlen(first_name));
    printf("Full name: %s\n",strcat(first_name,last_name));
    printf("%d\n",strcmp(other_name,another_name));
    if(strcmp(other_name,another_name)==0){
        printf("Both Strings are equal\n");
    }else{
        printf("Both Strings are not equal\n");
    }
    printf("fName: %s \n",first_name);
    printf("lName: %s \n",last_name);
    printf("aName: %s \n",another_name);

}