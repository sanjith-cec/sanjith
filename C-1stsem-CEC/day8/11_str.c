#include<stdio.h>
struct student{
    char name[30];
    int roll_num;
};
int main(){
    struct  student st1;
    printf("Enter a name: \n");
    scanf("%s",st1.name);
    printf("Enter a roll number: \n");
    scanf("%d",&st1.roll_num);

    printf("Student details: \n");
    printf("Name: %s\n",st1.name);
    printf("Roll No: %d\n",st1.roll_num);
}