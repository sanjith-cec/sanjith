#include<stdio.h>
int main(){
    int min = 0, arr[5];
    printf("Enter a Numbers: ");
    for(int i=0;i<=5-1;i++){
        scanf("%d",&arr[i]);
    }
    min =arr[0];
    for(int i =0; i<=5-1;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    printf("Min: %d",min);
}