#include<stdio.h>
void add();
int sub();
int main(){
    printf("Main Function \n");
    add();
    int res = sub();
    printf("Sub is: %d",res);

}

void add(){
    printf("Addition is: %d\n",(10+10));
}

int sub(){
    return 30-20;
}