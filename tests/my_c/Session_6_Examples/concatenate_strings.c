#include <stdio.h>
#include <string.h>

void main()
{
  char string[10] = {"123"};  	      	 //Extra space of incoming string
  char mystring[] = {'4','5','6'};       //No null terminating character
  
  strncat(string, mystring, 3); 	 //Copies only 3 characters and adds the null terminating character
  printf("String is : %s \n",string);
  
  strcat(string, mystring);              //Segmentation fault. It will work only if we add '\0' at mystring
  printf("String is : %s \n",string);
}

