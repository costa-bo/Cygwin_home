#ifndef __SORT_H__
#define __SORT_H__

#include <inttypes.h>

typedef int8_t (* callback)(int8_t, int8_t);

void sort(int8_t * , uint8_t, callback );



#endif
