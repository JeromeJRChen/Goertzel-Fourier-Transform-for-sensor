#include "GFT_fn.h"

void initialize(void)
{
	VALTYP3 i;
	N_sample = 100;
	Sampling_rate = 100;
	N_beam = 10;
	beam_width = 0;
	scale_pow_part = 12;
	scale_pow = 24;
	upper_limit = 1LL << (8*sizeof(VALTYP2)-2);
	lower_limit = 1;

	Target_freq = (VALTYP1*)malloc(N_beam * sizeof(VALTYP1));
	for (i = 0; i<N_beam; i++)
	{
		*Target_freq = i+1.;
		++Target_freq;
	}
	Target_freq = Target_freq - N_beam;
#ifdef FLOAT_VER
	scale_pow_part = 0;
	scale_pow = 0;
#endif

	scale = (VALTYP1)(1 << scale_pow);
	scale_part = (VALTYP1)(1 << scale_pow_part);
	pi = acos(-1.);
	n_GA = 0;

}