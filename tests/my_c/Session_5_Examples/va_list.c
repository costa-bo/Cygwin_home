#include <stdio.h>
#include <stdarg.h>

void print(int length, char type, ...)
{
  int i;
  
  va_list arg_list;
  
  va_start(arg_list, type );
  
  
  switch (type)
  {
    case 'c':
      for ( i = 0; i < length; i++)
      	printf("%c\t", va_arg( arg_list, char ));
      break;
    case 'i':	
      for ( i = 0; i < length; i++)
      	printf("%i\t", va_arg( arg_list, int ));
      break;
    default :
      printf("Unknown type");
  }  
  
  va_end(arg_list);
  
  printf("\n");

}

void main()
{
 
  print(4, 'c', 'M','G','I','F');
  print(3, 'i', 1, 2, 3);
   
}
