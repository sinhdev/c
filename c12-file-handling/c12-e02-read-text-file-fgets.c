#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f;
    
    f = fopen("text.txt", "r");
    
    if(f != NULL){
        char str[81];
        while((fgets(str, 80, f))!=NULL){
            str[strlen(str)-1] = '\0';
            puts(str);
        }
        
        fclose(f);
    } else {
        printf("Can't read text file.");
    }
    
    return 0;
}

