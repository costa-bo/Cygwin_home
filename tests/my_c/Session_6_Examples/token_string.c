#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
  char ip[] = "10.19.120.255";
  int token[4], i;
  char * str = NULL, * p_token = NULL;
  
  for ( i = 0, str = ip; i < 4; i++, str = NULL )
  {
    if( (p_token = strtok(str,".")) != NULL)
    {  
      token[i] = atoi(p_token);
      printf("Tokens of IPs %i\n",token[i]);
    }
  }
}
