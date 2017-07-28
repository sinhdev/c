#include <stdio.h>

int main()
{
    FILE *f;
    
    f = fopen("main.c", "r");
    
    if(f != NULL){
        char ch;
        while((ch=fgetc(f))!=-1){
            putchar(ch);
        }
        
        fclose(f);
    } else {
        printf("Can't read text file.");
    }
    
    return 0;
}

