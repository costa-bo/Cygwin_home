#include <stdio.h>
#include <errno.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

FILE * file_handle = NULL;
const char * file_name = "event_file.log";

unsigned short int open_file()
{
  if ((file_handle = fopen(file_name, "r")) == NULL)
  {
    printf("Failed to open '%s' : %s \n", file_name, strerror(errno));
    return FALSE;
  }
  else
  {
    printf("Sucessfully opened file: '%s' \n", file_name);
    return TRUE;
  }
}

void read_file()
{
  int value = 0, line_no = 0 ,result = 0;
  char input_line[100] = {0}, variable[31] = {0};

  for ( line_no = 0; (fgets(input_line, (sizeof(input_line)-1), file_handle)) != NULL; line_no++) /* reads maximum 99 bytes each time */
  { 
    result = sscanf (input_line,"%30s %*s %8d", variable, &value); /* asterisk skips read data */
    if( strncmp(variable, "#", 1) && result == 2 ) /* two arguments read and the line does not start with '#' */
      printf("%.30s  \t%d\n",variable, value);  
   }
}

void close_file()
{
  if( !fclose(file_handle))
    printf("Sucessfully closed file: '%s' \n", file_name);
  else
    printf("Failed to close '%s' : %s \n", file_name, strerror(errno));	
}


void main()
{
  if ( open_file() )
  {
    read_file();
    
    close_file();
  }
}




