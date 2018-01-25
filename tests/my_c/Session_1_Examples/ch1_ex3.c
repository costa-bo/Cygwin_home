#include <stdio.h>
#include <stdlib.h>

#define MAX_MGCO_ASC 1024

struct MGCO_CFG_PARMS {
unsigned int    Cluster_Identity;
unsigned int	Num_Mgs;
unsigned int	Num_Associations;
unsigned int	Num_Trids;
};

unsigned int MgcoAsc=1;
 
int main(int argc, char **argv)
{
   struct MGCO_CFG_PARMS Mgco_Cfg_Params;

   if (MgcoAsc <= 0)
    {
      Mgco_Cfg_Params.Cluster_Identity = 0;
      Mgco_Cfg_Params.Num_Mgs = 0;
      Mgco_Cfg_Params.Num_Associations = 0;
      Mgco_Cfg_Params.Num_Trids = 0;
      printf ("Mgco Association invalid : %d \n", MgcoAsc);
    }
   else
    {
     unsigned int  	Cluster_Identity=1;
     unsigned int	Num_Mgs=5;
     unsigned int	Num_Associations=1;
     unsigned int	Num_Trids=1;

     struct MGCO_CFG_PARMS Mgco_Params;

     Mgco_Params.Cluster_Identity = Cluster_Identity;
     Mgco_Params.Num_Mgs = Num_Mgs;
     Mgco_Params.Num_Associations = Num_Associations;
     Mgco_Params.Num_Trids = Num_Trids;

     printf ("Cluster_Identity : %d \n", Cluster_Identity);
     printf ("Num_Mgs : %d \n", Num_Mgs);
     printf ("Num_Associations : %d \n", Num_Associations);
     printf ("Num_Trids : %d \n", Num_Trids);
     printf ("Size of MGCO_PARMS : %zu\n", sizeof(Mgco_Cfg_Params));
    }
     system ("pause");
   return 0;
}

