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
    
    //Binary Search
    int step = 0, fIndex = -1;
    int low = 0, hi = count-1, mid;
    while(low <= hi){
    	step++;
    	if(a[low] == f){
    		fIndex = low;
    		break;
    	}
    	if(a[hi] == f){
    		fIndex = hi;
    		break;
    	}
    	
    	mid = (hi + low) / 2;
    	if(a[mid] == f){
    		fIndex = mid;
    		break;
    	} else if(f < a[mid]){
    		hi = mid - 1;
    	} else {
    		low = mid + 1;
    	}
    }
    
    if(fIndex==-1){
        printf("%d not found in array.\n", f);
    }else{
        printf("%d found in array at index %d after %d steps.\n", f, fIndex, step);
    }

    return 0;
}
