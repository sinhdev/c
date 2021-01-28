#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a;
    int count, i;
    
    printf("Input array size: ");
    scanf("%d", &count);
    
    //alloc memory
    a = (int*)calloc(count, sizeof(int));
    
    //input array:
    for(i=0; i<count; i++){
        printf("a[%d] = ", i);
        scanf("%d", a + i);
    }

    a = (int*)realloc(a, (count+1)*sizeof(int));
    //input new element
    printf("a[%d] = ", count);
    scanf("%d", a + count);
    count++;
    
    //display array:
    printf("\nArray:\n");
    printf("[");
    for(i=0; i<count; i++){
        printf("%d ", a[i]);
    }
    printf("]\n");
	
	//free memory
	free(a);
	
    return 0;
}

