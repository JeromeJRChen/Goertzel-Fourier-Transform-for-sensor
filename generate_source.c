#include "GFT_fn.h"

void generate_source(VALTYP2* source)
{
	VALTYP3 i;

	for (i = 0; i<N_SAMPLE; i++)
	{
#ifdef FLOAT_VER
		*source = sin(2 * 2 * pi*i / Sampling_rate)*scale;
#endif
#ifdef FIXED_VER
		*source = (VALTYP2)(round(sin(2 * 2 * pi*i / Sampling_rate)*scale));
#endif
		++source;
	}
	source = source - N_SAMPLE;
}
