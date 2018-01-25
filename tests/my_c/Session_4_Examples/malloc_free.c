#include <stdio.h>
#include <stdlib.h>

typedef enum  { /* VODOC Overload Status Codes*/
    VOD_OC_NO_OVLD = 0,
    VOD_OC_LOW_OVLD,
    VOD_OC_MED_OVLD,
    VOD_OC_HIGH_OVLD_0,
    VOD_OC_HIGH_OVLD_1,
    VOD_OC_HIGH_OVLD_2,
    VOD_OC_HIGH_OVLD_3,
    VOD_OC_HIGH_OVLD_4,
    VOD_OC_HIGH_OVLD_5,
    VOD_OC_HIGH_OVLD_6,
    VOD_OC_OVLD_NUM,
    VOD_OC_OVLD_MIN = 0,
    VOD_OC_OVLD_MAX = (VOD_OC_OVLD_NUM-1)
} VOD_OC_OVLD_STATUS_T;

typedef unsigned char boolean_t;
#define B_TRUE 1
#define B_FALSE 0

typedef struct{    /* ODM Status Data */
    VOD_OC_OVLD_STATUS_T  OvldStatus;
    boolean_t             isValid;
} VOD_OC_OPODM_INFO_S;	

int main(){
    VOD_OC_OPODM_INFO_S *pOvldHistory = NULL;

    pOvldHistory = (VOD_OC_OPODM_INFO_S *) malloc(60 * sizeof(VOD_OC_OPODM_INFO_S));
    if(pOvldHistory == NULL){   // Memory was not allocated.
        printf("Not enough memory. Exiting with error! \n");
        return 1;
    }
    // Do useful stuff
    printf("Address of pOvldHistory is: 0x%p\n",&pOvldHistory);
    printf("Address of malloc'ed memory is: 0x%p\n",pOvldHistory);
    free(pOvldHistory);
    printf("After free(), pOvldHistory points to 0x%p\n", pOvldHistory);
    pOvldHistory = NULL;

    return 0;
}

