#include<stdio.h>
void print(int n);

int main(){
    int num = 0;
    printf("Enter a Value: ");
    scanf("%d",&num);
    print(num);
}

void print(int n){
    if(n<=0){
        return;
    }
    printf("%d ",n);
    print(n-1);
}