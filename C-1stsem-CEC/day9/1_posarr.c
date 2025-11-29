#include<stdio.h>
int main(){
    int arr[50], pos=0,ele=0,size=0;
    printf("Enter a size of array: \n");
    scanf("%d",&size);
    if(size>50){
        printf("Array out of bound\n");
    }else{
        //to insert
        printf("Enter elements: \n");
        for(int i=0;i<size;i++){
            scanf("%d",&arr[i]);
        }

        printf("Enter a elemnt to insert: \n");
        scanf("%d",&ele);
        printf("Enter a Position: \n");
        scanf("%d",&pos);
        for(int i = size-1;i>=pos-1;i--){
            arr[i+1]=arr[i];
        }
        arr[pos-1]=ele;
        size++;
        printf("Array elements: \n");
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
        }
    }
}