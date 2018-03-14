#include "GFT_fn.h"

void initialize(void)
{
	VALTYP3 i;
	Sampling_rate = 9;
	beam_width = 0;
	scale_pow_part = 9;
	scale_pow = 18;
#ifdef FLOAT_VER
	scale_pow_part = 0;
	scale_pow = 0;
#endif
	scale = (VALTYP1)(1LL << scale_pow);
	scale_part = (VALTYP1)(1LL << scale_pow_part);
	pi = acos(-1.);
}
