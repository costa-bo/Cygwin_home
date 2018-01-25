#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef unsigned int uint_t;
#define UINT32_MAX 4294967295

struct MGCO_CFG_PARMS{
uint Mg_Min_Resp_Timer;
uint Mg_UB_Resp_Timer;
uint Num_Mgs;
uint Num_Associations;
uint UDP_Port_Start_Number;
};

int mgcoTimerDelta(int asc, uint_t csrt)
{
    uint_t         delta = 0;
    uint_t         seedx = 0;
    uint_t         randx = 0;

    printf("Enter mgco_timer_delta\n");

    seedx = time(NULL);
    printf("seedx=%u\n",seedx);
    randx = seedx;
    randx = randx * 1103515245 + 12345;

    delta = csrt / 2 + randx / ((UINT32_MAX / (csrt / 2)) + 1);

    printf("asc=%d randx=%u csrt=%u delta=%u\n",
            asc,randx,csrt,delta);

    printf("Exit mgco_timer_delta\n");
    return(delta);
}

int main()
{
    int new_timer_value = -6720327918;
    long int last_icmp_message_time = 0;
    long int receive_time = 0;
    int asc=5;
    struct MGCO_CFG_PARMS cfg_table;

    cfg_table.Mg_Min_Resp_Timer        =  400;
    cfg_table.Mg_UB_Resp_Timer         =  4000;
    cfg_table.Num_Mgs                  =  1024;
    cfg_table.Num_Associations         =  1024;
    cfg_table.UDP_Port_Start_Number    =  0;

    new_timer_value += mgcoTimerDelta(asc,new_timer_value);

    printf("new_timer_value before if=%d\n",new_timer_value);

    if (cfg_table.Mg_Min_Resp_Timer != (uint)-1 &&
        //new_timer_value < (int)cfg_table.Mg_Min_Resp_Timer)
        new_timer_value < (int)cfg_table.Mg_Min_Resp_Timer)
    {
        new_timer_value = cfg_table.Mg_Min_Resp_Timer;
    } 
    else if (cfg_table.Mg_UB_Resp_Timer != (uint) -1 &&
               new_timer_value > cfg_table.Mg_UB_Resp_Timer)
    {
        new_timer_value = cfg_table.Mg_UB_Resp_Timer;
    }

    printf("new_timer_value=%d\n",new_timer_value);
    printf("(uint)-1=%x\n", (uint)-1);

return 0;
}
