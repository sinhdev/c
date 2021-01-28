#include <stdio.h>

int main () {

   char str[30];
   printf("Input your name: ");
   //warning: the 'gets' function is dangerous and should not be used
   gets(str);
   printf("Your name: %s\n", str);
   return 0;
}

