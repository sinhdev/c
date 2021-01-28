#include <stdio.h>
 
int main () {

   int i;
	
   /* for loop execution */
   for( i = 10; i < 20; i = i + 1 ){
      if( i== 13){
          break;
      }
      printf("value of i: %d\n", i);
   }
 
   return 0;
}

