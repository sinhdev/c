#include <stdio.h>

int main()
{
    int ary[10] = {10, 21, 32, 43, 54, 65, 76, 87, 98, 99};
	int i;
	for (i = 0; i < 10; i ++)
	{
	    printf("\ni=%d,ary[i]=%d,*(ary+i)=%d", i, ary[i], *(ary + i));
	    printf("&ary[i]=%X,ary+i=%X", &ary[i],ary+i);
	}
	
    return 0;
}

