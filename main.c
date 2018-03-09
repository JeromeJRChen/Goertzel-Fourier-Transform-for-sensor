/*
 * GFT_FixedPoint.c
 * using shift operator only for fixed point
 */

//#include <stdio.h>
#include <msp430.h>
#include "ValueType.h"
#include "GlobalDeclared.h"
#include "GFT_fn.h"

VALTYP2* GFT;

VALTYP3 main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    VALTYP2* source;
//    VALTYP2* GFT;
    VALTYP3 i;

    initialize();
    GFT = (VALTYP2*)malloc(N_beam * sizeof(VALTYP2));
    generate_source(&source);
//  read_data(&source);

    for (i = 0; i<N_beam; i++)
    {
        band_width(GFT, source, *Target_freq, beam_width);
//#ifdef FLOAT_VER
//        printf("freq = %f, GFT = %f\n", *Target_freq, *GFT);
//#endif
//#ifdef FIXED_VER
//        printf("freq = %f, GFT = %ld\n", *Target_freq, *GFT);
//#endif
        ++GFT;
        ++Target_freq;
    }
    GFT = GFT - N_beam;
    Target_freq = Target_freq - N_beam;

//    effi_check(n_GA);

    free(source);
    free(Target_freq);
    free(GFT);

//    system("Pause");
    while (1)
    {

    }
    return 0;
}
