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
    
    //selection sort
    int j, temp, iMin, step = 1;
    for(i=0; i<count-1; i++){
    	iMin = i;
    	for(j=i+1; j<count; j++, step++){
    		if(a[j] < a[iMin]){
    			iMin = j;
    		}
    	}
    	if(iMin != i){
    		temp = a[i];
    		a[i] = a[iMin];
    		a[iMin] = temp;
    	}
    }
    printf("\nSorted Array (Selection Sort): %d steps\n", step);
    for(i=0; i<count; i++){
    	printf("%8d", a[i]);
    }

    return 0;
}
