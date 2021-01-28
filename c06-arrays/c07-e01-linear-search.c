#include <stdio.h>

int main()
{
    int a[1000], i, count=1000;
    int f;
    
    //init array
    for(i=0; i<count; i++){
        a[i] = i + 1;
    }
    
    //input f
    printf("Input a integer number: ");
    scanf("%d", &f);
    
    //Linear Search
    int step = 0, fIndex = -1;
    for(i=0; i<count; i++, step++){
        if(a[i] == f){
            fIndex = i;
            break;
        }
    }
    
    if(fIndex==-1){
        printf("%d not found in array.\n", f);
    }else{
        printf("%d found in array at index %d after %d steps.\n", f, fIndex, step);
    }

    return 0;
}
