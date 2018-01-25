#include <stdio.h>

typedef enum         /* VODOC Overload Status Codes*/
{
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
typedef struct                        /* ODM Status Data */
{
        VOD_OC_OVLD_STATUS_T  OvldStatus;
        boolean_t             isValid;
} VOD_OC_OPODM_INFO_S;

int main()
{
  VOD_OC_OPODM_INFO_S ovld_info_min[60];
        VOD_OC_OPODM_INFO_S *ptr = NULL;

        printf("sizeof VOD_OC_OVLD_STATUS_T: %d\n", sizeof(VOD_OC_OPODM_INFO_S));
        printf("sizeof ovld_info_min: %d\n", sizeof(ovld_info_min));
        printf("The array is located at 0x%p\n", ovld_info_min);
        getchar(); // Just for pause

        for(ptr = ovld_info_min; ptr <= &ovld_info_min[59]; ptr++)
        {
                ptr->OvldStatus = VOD_OC_NO_OVLD;
                ptr->isValid = B_FALSE;
                printf("The element #%d is at address 0x%p\n", ptr - ovld_info_min, ptr);
        }
        getchar(); // Just for pause

        // Find first valid element of ovld_info_min
        ptr = ovld_info_min;
        while(ptr - ovld_info_min < 60 && ptr->isValid != B_TRUE)
        {
                printf("Checking element %d\n",ptr - ovld_info_min);
                ptr++;
        } // This will cause SIGSEGV
        getchar(); // Just for pause

        return 0;
}
