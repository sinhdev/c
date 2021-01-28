#include <stdio.h>

int main() {
    
    int choice;
	choice = 0;
	printf("Enter Choice (1 - 3) : ");
	scanf("%d", &choice);
	if (choice == 1){
		printf ("Choice is 1\n");
	} else if ( choice == 2){
		printf ("Choice is 2\n");
	} else if ( choice == 3){
		printf ("Choice is 3\n");
	} else {
		printf ("Invalid Choice\n");
	}
	
   return 0;
}

