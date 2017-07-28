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
    
    //insertion sort
    int j, temp, valueToInsert, holePosition, step = 1;
    for(i=1; i<count; i++){
    	holePosition = a[i];
    	valueToInsert = i;
    	while(valueToInsert>0 && a[valueToInsert-1] > holePosition){
    		a[valueToInsert] = a[valueToInsert-1];
    		valueToInsert--;
    		step++;
    	}
    	a[valueToInsert] = holePosition;
    }
    printf("\nSorted Array (Insertion Sort): %d steps\n", step);
    for(i=0; i<count; i++){
    	printf("%8d", a[i]);
    }

    return 0;
}
