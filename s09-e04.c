#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a;
    int count, i;
    
    printf("Input array size: ");
    scanf("%d", &count);
    
    //alloc memory
    a = (int*)calloc(count*sizeof(int));
    
    //input array:
    for(i=0; i<count; i++){
        printf("a[%d] = ", i);
        scanf("%d", a + i);
    }
    
    //display array:
    printf("\nArray:\n");
    for(i=0; i<count; i++){
        printf("%8d", a[i]);
    }
	
	//free memory
	free(a);
	
    return 0;
}

