#include <stdio.h>

int main(int count, char* args[])
{
    int size;
    
    size = sizeof(int);
    printf("\nint: %d bytes\n", size);
    size = sizeof(long int);
    printf("long int: %d bytes\n", size);
    size = sizeof(double);
    printf("double: %d bytes\n", size);
    size = sizeof(long double);
    printf("long double: %d bytes\n", size);

    return 0;
}


