#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[100], i, count = 100;
    
    srand(time(NULL));
    
    //init array random
    for(i=0; i<count; i++){
    	a[i] = rand() % 1000;
    }
    
    printf("Array:\n");
    for(i=0; i<count; i++){
    	printf("%8d", a[i]);
    }
    
    //bubble sort
    int j, temp, step = 1;
    for(i=0; i<count-1; i++){
    	for(j=0; j<count-1; j++, step++){
    		if(a[j] > a[j+1]){
    			temp = a[j];
    			a[j] = a[j+1];
    			a[j+1] = temp;
    		}
    	}
    }
    printf("\nSorted Array (Bubble Sort): %d steps\n", step);
    for(i=0; i<count; i++){
    	printf("%8d", a[i]);
    }

    return 0;
}
