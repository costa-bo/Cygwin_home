#include <stdio.h>
#include <stdlib.h>

int mgcoAscEntry=-1;
int mgcoMaxAscNumber=100;
void printMgcoAsc();

int main()
{
    int i;
    
    for (i=0; i<mgcoMaxAscNumber; i++) 
    {
        printMgcoAsc(); 
        printf("mgcoAscEntry in main is %d\n",mgcoAscEntry);
        
    }
return 1;
}
