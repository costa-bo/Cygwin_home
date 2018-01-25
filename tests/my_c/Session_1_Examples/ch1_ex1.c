#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iterator;
    
    for (iterator=0; iterator<5; ++iterator) 
    {
        int  faxGlarePreventionSt=3;
        static int  faxGlarePrevention=1; 
        
        printf("faxGlarePreventionSt=%d faxGlarePrevention %d\n",
        				faxGlarePreventionSt, faxGlarePrevention);
        
        ++faxGlarePreventionSt;
        ++faxGlarePrevention;

   }
   system ("pause");
return 0;
}
