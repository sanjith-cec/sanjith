#include <stdio.h>
struct student {
    int id;
    float marks;

};
int main() {
    int a=25;
    float b = 45.6;
    char c = 'Z';
    struct student s1 ={1,98.5};


    int *p1 = &a;
    float *p2 = &b;
    char *p3 = &c;
    struct student *p4 = &s1;
    printf("int pointer *p1  =%p-> value = %d \n", p1, *p1);
    printf("float pointer *p2 = %p-> value = %.2f\n", p2, *p2);
    printf("char poinmter *p3 = %p-> value = %c\n", p3,*p3);
    printf("struct pointer *p4 =%p -> id = %d, marks  = %.2f\n",
    p4, p4->id, p4->marks);
}


