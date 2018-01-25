#include "sort.h"


void sort(int8_t * array, uint8_t length, callback comparison)
{
    int8_t i, j, key;
    
    for(j = 1; j < length; j++)
    {
				key = array[j];
	
        i = j - 1;

				while( i >= 0 && comparison(array[i], key) )
        {
            array[i+1] = array[i];
            i -= 1;
        }
         
				array[i+1] = key;
    }
}
