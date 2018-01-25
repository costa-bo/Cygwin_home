#include <stdio.h>
#include <stdlib.h>

extern int mgcoAscEntry;

void printMgcoAsc()
{
    printf("mgcoAscEntry in printMgcoAsc()is :%d\n",mgcoAscEntry);
    ++mgcoAscEntry;
}
