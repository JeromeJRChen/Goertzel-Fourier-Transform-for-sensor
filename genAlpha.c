#include <GFT_fn.h>

void genAlpha(VALTYP2* alpha_out, VALTYP3 k)
{

    VALTYP2 alpha[9] = { 0, 240, 846, 1536, 1986, 1986, 1536, 846, 240 };
    *alpha_out = alpha[k];
}
