#include <stdio.h>

void main()
{
    int an_array[60];
    unsigned short i; // 2 bytes

    i = 59;
    while (i >= 0) /* Condition is wrong... i will never become negative, because it is unsigned short! */
    {
        // do something with an_array[i]
        an_array[i] = i;
        i--;
    }
}
