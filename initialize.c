#include "GFT_fn.h"

void initialize(void)
{
	VALTYP3 i;
	N_sample = 9;
	Sampling_rate = 9;
	N_beam = 4;
	beam_width = 0;
	scale_pow_part = 9;
	scale_pow = 18;
	upper_limit = 1LL << (8*sizeof(VALTYP2)-2);
	lower_limit = 1;

	Target_freq = (VALTYP1*)malloc(N_beam * sizeof(VALTYP1));
	for (i = 0; i<N_beam; i++)
	{
		*Target_freq = i;
		++Target_freq;
	}
	Target_freq = Target_freq - N_beam;
#ifdef FLOAT_VER
	scale_pow_part = 0;
	scale_pow = 0;
#endif

	scale = (VALTYP1)(1LL << scale_pow);
	scale_part = (VALTYP1)(1LL << scale_pow_part);
	pi = acos(-1.);
	n_GA = 0;

}
