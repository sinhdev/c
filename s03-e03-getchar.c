#include <stdio.h>

int main(int count, char* args[])
{
    char letter;
	printf("\nPlease enter any character:");
	letter = getchar();
	printf("\nThe character entered by you is %c", letter);

    return 0;
}


