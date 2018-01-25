#include <stdio.h>
#include <string.h>

typedef struct
{
  char type[30];
  int value;
} CODEC;

CODEC set_codec_by_value   (char [30], int);
void  set_codec_by_pointer (char [30], int, CODEC *);
void  set_codec_erronuous  (char [30], int, CODEC);


void main()
{
   CODEC codec = {"", 0}; /* Standart C initialization */
/* CODEC codec = { .type = "", .value = 0}; ANSI C initialization */
	
   printf("The code is : %s %i\n", codec.type, codec.value);
	
   codec = set_codec_by_value("FAX", 1);
	
   printf("The code is : %s %i\n", codec.type, codec.value);
	
   set_codec_by_pointer("MODEM", 2, &codec);

   printf("The code is : %s %i\n", codec.type, codec.value);

   set_codec_erronuous("VOICE", 3, codec);

   printf("The code is : %s %i\n", codec.type, codec.value);
}


CODEC set_codec_by_value (char type[30] , int value)
{
  CODEC codec;
	
  strcpy(codec.type, type);
  codec.value = value;
	
  return codec;
}

void set_codec_by_pointer (char type[30] , int value, CODEC * p_codec)
{
	
  strcpy(p_codec->type, type);
  p_codec->value = value;
		
}

void set_codec_erronuous (char type[30] , int value, CODEC codec)
{
	
  strcpy(codec.type, type);
  codec.value = value;
	
  printf("The code locally is : %s %i\n", codec.type, codec.value);
		
}
