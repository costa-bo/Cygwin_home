#include <stdio.h>


typedef enum
{
    VT_FMST_VOICE             /*  Initial state voice  */
   ,VT_FMST_G711_FAX          /*  G711 fax state       */
   ,VT_FMST_G711_MODEM        /*  G711 modem state     */   
   ,VT_FMST_T38               /*  T38 state            */
   ,VT_FMST_V152              /*  V152 state           */
} VT_FMST_STATE;

typedef struct 
{
  VT_FMST_STATE en;
  char * string;
} VT_FMST_STATE_en_conversion_t;

static VT_FMST_STATE_en_conversion_t VT_FMST_STATE_en_conversion[] =
{
   #define _x_(_e_) {_e_, (char *)#_e_ }
      _x_ (VT_FMST_VOICE),
      _x_ (VT_FMST_G711_FAX),
      _x_ (VT_FMST_G711_MODEM),
      _x_ (VT_FMST_T38),
      _x_ (VT_FMST_V152),

      { (VT_FMST_STATE)-1, (char *)0 } 
   #undef _x_ 
};


char * VT_FMST_STATE_string (VT_FMST_STATE en)
{
    VT_FMST_STATE_en_conversion_t *p;

    if ( ( en >= 0 ) && 
         ( en < (sizeof(VT_FMST_STATE_en_conversion) / sizeof(VT_FMST_STATE_en_conversion[0])) ) && 
         ( en == VT_FMST_STATE_en_conversion[en].en) )
    {
       /* table and enum in same order */        
       return VT_FMST_STATE_en_conversion[en].string;
    }

    for (p = VT_FMST_STATE_en_conversion; p->string; p++)
    {
        if (p->en == en)
	   return p->string;
    }
    
    return (char *)"?VT_FMST_STATE";   /* indicator for "no such enum" */
}


void main()
{
  printf("FaxModemState = %s \n",VT_FMST_STATE_string(VT_FMST_G711_FAX));
}
