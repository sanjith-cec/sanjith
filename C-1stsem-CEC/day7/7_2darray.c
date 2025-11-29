#include<stdio.h>
int main(){
    int marks[2][2];

    printf("Enter the elements: ");
    for(int i=0;i<2;i++){//2
        for(int j=0;j<2;j++){//2
            scanf("%d",&marks[i][j]);//marks[1][1]
        }
    }
    printf("Array elements: \n");
    for(int i=0;i<2;i++){//2
        for(int j=0;j<2;j++){//2
            printf("%d ",marks[i][j]);//marks[1][1]
        }
        printf("\n");
    }


}