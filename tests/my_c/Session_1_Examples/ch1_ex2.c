#include <stdio.h>
#include <stdlib.h>


int mGCO_INFO_STRING = 10;

struct MGCO_CFG_PARMS {
unsigned int    Cluster_Identity;
unsigned int	Num_Mgs;
unsigned int	Num_Associations;
unsigned int	Num_Trids;
};

struct MGCO_GLOBALS {
    struct MGCO_CFG_PARMS cfg;
    int         mgco_started;
    int         mgco_trace_id;
    int         Num_Mgco_Minor;
    int         Num_Mg_Buckets;
    int         Asc_Itrid_Buckets;
char        mgco_drv_ver[sizeof(mGCO_INFO_STRING) + 1];
};

int main(int argc, char **argv)
{
   struct MGCO_CFG_PARMS Test_Struct_1;
   struct MGCO_GLOBALS Test_Struct_2;
   printf ("Size of char : %d \n",sizeof(char));
   printf ("Size of int : %d \n",sizeof(int));
   printf ("Size of short int : %d \n",sizeof(short int));
   printf ("Size of long int : %d \n",sizeof(long int));
   printf ("Size of float : %d \n",sizeof(float));
   printf ("Size of double : %d \n",sizeof(double));
   printf ("Size of MGCO_CFG_PARMS : %zu\n", sizeof(Test_Struct_1));
   printf ("Size of MGCO_GLOBALS : %zu\n", sizeof(Test_Struct_2));
   system ("pause");
   return 0;
}
