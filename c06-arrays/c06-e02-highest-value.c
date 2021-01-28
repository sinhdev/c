#include <stdio.h>

int main()
{
    int ary[10];
    int i, total, high;
    for(i=0; i<10; i++)
    {
        printf("ary[%d] = ", i);
	    scanf("%d",&ary[i]);
    }
    /* Displays highest of the entered values */
    high = ary[0];
    for(i=1; i<10; i++)
    {
        if(ary[i] > high)
            high = ary[i];
    }
    printf("Highest value entered was %d\n", high);

    return 0;
}

