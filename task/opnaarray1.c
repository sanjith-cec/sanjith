#include <stdio.h>
int main()
 {
     int arr[10] = {10,20,30,40,50};
     int size =5;
     int pos =2;
     int value =25;
      
      //shift elements to the right
      for (int i = size; i > pos; i--)
     {
         arr[i] = arr [i-1];
     }
     arr[pos] = value;
      size++; 
      
      printf("array after insertion:\n");
      for(int i = 0; i < size; i++){
      printf("%d\n", arr[i]);
 }
    return 0; 
 }



 #include <stdio.h>
int main()
 {
     int arr[10] = {10,20,30,40,50,60,70};
     int size =7;
     int pos =3;
     int value =48;
      
      //shift elements to the right
      for (int i = size; i > pos; i--)
     {
         arr[i] = arr [i-1];
     }
     arr[pos] = value;
      size++; 
      
      printf("array after insertion:\n");
      for(int i = 0; i < size; i++){
      printf("%d\n", arr[i]);
 }
    return 0; 
 }