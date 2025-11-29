#include<stdio.h>
int main(){
    printf("Numbers from 1 to 10: \n");
    for(int i = 1; i<= 100;i++){
        if(i%2==0){
            printf("%d ",i);
        }
    }
}