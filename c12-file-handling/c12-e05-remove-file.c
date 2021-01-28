#include <stdio.h>

int main(int argCount, char **args){
    int i;
    for(i=0; i<argCount; i++){
        remove(args[i]);
    }
    return 0;
}