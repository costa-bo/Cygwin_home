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
        int i = 0;
        VOD_OC_OPODM_INFO_S ovld_info_min[60];

        printf("sizeof VOD_OC_OVLD_STATUS_T: %d\n", sizeof(VOD_OC_OPODM_INFO_S));
        printf("sizeof ovld_info_min: %d\n", sizeof(ovld_info_min));

        printf("The array is located at 0x%p\n", ovld_info_min);
        getchar(); // Just for pause... Press enter to continue.
        for(i=0; i<60; i++)
        {
                //ovld_info_min[i] = {VOD_OC_NO_OVLD, B_FALSE};
                ovld_info_min[i].OvldStatus = VOD_OC_NO_OVLD;
                ovld_info_min[i].isValid = B_FALSE;
                printf("The element #%d is at address 0x%p\n", i, &ovld_info_min[i]);
        }
        getchar(); // Just for pause... Press enter to continue.
        // Find first valid element of ovld_info_min
        for (i=0; i < 60 && ovld_info_min[i].isValid != B_TRUE; i++);

        if (i < 60)
                printf("The first element with valid data is %d\n", i);
        else
                printf("Element not found.\n");
                
        getchar(); // Just for pause... Press enter to continue.

        return 0;
}
