#include <stdio.h>

int main(int argCount, char** args){
    char str[11];
    printf("input a string: ");
    fgets(str, 11, stdin);
    //clear keyboard buffer windows
    fflush(stdin);
    //clear keyboard buffer unix
    fseek(stdin, 1, SEEK_END);
    printf("str = \"%s\"\n", str);
    putchar(getchar());

    return 0;
}