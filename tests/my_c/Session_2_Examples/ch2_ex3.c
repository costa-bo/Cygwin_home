#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t;

typedef union {
  uint8_t   value;
  struct {
    uint8_t version : 3;
    uint8_t flags   : 3;
  } bits;
} CopsVersionFlags_bf;

typedef struct {
    uint8_t version : 2;
    uint8_t flags   : 2;
}bfStruct;

typedef union {
  uint8_t   value;
  struct {
    uint8_t version;
    uint8_t flags;
  } bits;
} CopsVersionFlags_s;

int main()
{
CopsVersionFlags_bf bfUnion;
CopsVersionFlags_s sUnion;
bfStruct bfS;
printf("Memory size of BF union : %d\n",sizeof(bfUnion)); 
printf("Memory size of standard union : %d\n",sizeof(sUnion));
printf("Memory size of BF stract: %d\n",sizeof(bfS));

bfS.version = 4 ; 
/*bfS.version = 2 ;
bfS.version = 7 ;
bfS.version = 8 ;*/
printf("bfS.version: %d\n",bfS.version);

bfUnion.bits.version = 4 ; 
/*bfUnion.version = 2 ;
bfUnion.version = 7 ;
bfUnion.version = 8 ;*/

printf("bfS.version: %d\n",bfUnion.bits.version);
return 0;
}
