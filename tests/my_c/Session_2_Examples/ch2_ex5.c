#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum{
    One = 1,
    Two,
    Three
}numbers;
int threes = 0;
int iterations = 0;
int randomInt = 0;

int main()
{
    for(;;) 
    {
        

        srand(time(NULL));
        randomInt = ((3*rand())/(RAND_MAX+1))+1;

        iterations++;
        printf("iterations= %d\n", iterations);
        printf("randomInt= %d\n", randomInt);

        if (randomInt == One) 
        { 
            printf("Don't care about one,continue!\n");
            continue;
        }

        if (randomInt == Two) 
        { 
            printf("Invalid number, exiting!\n");
            continue;
        }

        if (randomInt == Three) 
        { 
            printf("Increment three counter!\n");
            ++threes;
            continue;
        }
	
	if (iterations > 20)
        {
            printf("Max iterations reached, exiting!\n");  
            break;
        }

        
    }

    return 0;
}
