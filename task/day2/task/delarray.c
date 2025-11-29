#include <stdio.h>

int main()
 {
     int arr[10] = { 10 , 20 , 25 , 30 , 40 , 50 };
     int size = 6;
     int pos =4;
      
      //shift elements to the right
      for (int i = pos; i < size -i; i++)
     {
         arr[i] = arr[i+1];
     }
     
      size-- ; 
      
      printf("array after insertion:\n");
      for(int i = 0; i < size; i++) 
      {
         printf("%d", arr[i]);
      }
 return 0;
}