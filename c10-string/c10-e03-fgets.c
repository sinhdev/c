#include <stdio.h>
#include <string.h>

int main () {

   char str[30];
   printf("Input your name: ");
   fgets(str, 29, stdin);
   str[strlen(str)-1] = '\0';
   printf("Your name: %s\n", str);
   return 0;
}

