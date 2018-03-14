/*
 * GFT_FixedPoint.c
 * using shift operator only for fixed point
 */

#include <msp430.h>
#include "ValueType.h"
#include "GlobalDeclared.h"
#include "GFT_fn.h"

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    VALTYP3 i;

    initialize();
    VALTYP2 source[N_SAMPLE];
    VALTYP1 Target_freq[N_BEAM] = {0, 1, 2, 3};
    VALTYP2 GFT[N_BEAM];
    generate_source(source);

    for (i = 0; i<N_BEAM; i++)
    {
        band_width(GFT+i, source, Target_freq[i], beam_width);
    }

    while(1)
    {

    }
}
