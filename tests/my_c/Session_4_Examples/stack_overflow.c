#include <stdio.h>

int main()
{
    int nStack[3 * 1024 * 1024];
	
    printf("Size of nStack is: %d\n",sizeof(nStack));

    nStack[3 * 1024 * 1024 - 1] = 0;
    return 0;
}
