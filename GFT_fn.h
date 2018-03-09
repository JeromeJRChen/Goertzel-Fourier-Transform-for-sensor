#ifndef GFT_FN_H__
#define GFT_FN_H__

#include <math.h>
#include <stdlib.h>
#include "ValueType.h"
#include "GlobalDeclared.h"

void initialize(void);
void read_data(VALTYP2**);
void generate_source(VALTYP2**);
void GoerFT(VALTYP2*, VALTYP3, VALTYP2*);
void band_width(VALTYP2*, VALTYP2*, VALTYP1, VALTYP1);
void effi_check(VALTYP3);

#endif
 
