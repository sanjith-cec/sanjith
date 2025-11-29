#include<stdio.h>

struct address
{
   char city[20];
   int pincode;
};

struct student
{
    char name[30];
    int roll_no;
    struct address addr;//nested structure
};

int main()
{
    struct student s1 = {"Rahul", 101,{"Banglure",560001}};
    printf("%s-%d-%s-%d",s1.name,s1.roll_no,s1.addr.city,s1.addr.pincode);
    return 0;
}