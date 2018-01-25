#include <stdio.h>
#include "sort_array.h"
#include "sort.h"



void main()
{

  int8_t array[] = {9,8,4,2,5,1,8,-1,0,3};
  uint8_t length = 0;
  
  length = sizeof(array); // this is valide due to size in bytes

  print_array(array, length);
      
  sort(array, length, ascending);
  
  print_array(array, length);
  
  sort(array, length, descending);
  
  print_array(array, length);

}

int8_t ascending(int8_t x, int8_t y)
{
  return x > y;
}

int8_t descending(int8_t x, int8_t y)
{
  return x < y;
}

void print_array( int8_t * array, uint8_t length)
{
  uint8_t i;
  
  printf("Print array\n");
 
  for(i = 0; i < length; i++)
    printf("%d\t", array[i]);
  
  printf("\n");
}
