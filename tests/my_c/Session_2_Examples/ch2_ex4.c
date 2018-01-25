#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum{
    One = 1,
    Two
}numbers;

int main()
{
    int while_condition = 1;
    int iterations = 0;
    int randomInt = 0;
    
    while(while_condition == 1)
    {
      iterations++;
      srand(time(NULL));
      randomInt = ((2*rand())/(RAND_MAX+1))+1;
      printf("randomInt= %d\n", randomInt);

       if (iterations > 5){while_condition = 0; }

      switch (randomInt)
      {
                     
       case One: printf("One detected!\n"); break;
       case Two: printf("Two detected!\n"); break;
       default: break;
    
      }
    }
    return 0;
}

