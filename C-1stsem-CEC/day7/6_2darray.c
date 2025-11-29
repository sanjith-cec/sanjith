#include<stdio.h>
int main(){
    int marks[2][2];
    marks[0][0] = 40;
    marks[0][1] = 50;
    marks[1][0] = 60;
    marks[1][1] = 70;
    printf("1st: %d\n",marks[0][0]);
    printf("2st: %d\n",marks[0][1]);
    printf("3st: %d\n",marks[1][0]);
    printf("4st: %d\n",marks[1][1]);
}