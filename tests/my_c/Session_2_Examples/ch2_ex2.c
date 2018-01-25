#include <stdio.h>
#include <stdlib.h>

typedef unsigned char      uint8_t;
typedef unsigned short int uint16_t;

typedef union {
  uint16_t   value;
  struct {
    uint8_t version;
    uint8_t flags;
  } bits;
} CopsVersionFlags_s;

int main()
{
CopsVersionFlags_s sUnion;
printf("Memory size of Union : %d\n",sizeof(sUnion));

sUnion.value = 1;
printf("sUnion.value = %d\n",sUnion.value);
sUnion.bits.version = 10;
printf("sUnion.bits.version = %d\n",sUnion.bits.version);
sUnion.bits.flags =   100;
printf("sUnion.bits.flags = %d\n",sUnion.bits.flags);

return 0;
}
