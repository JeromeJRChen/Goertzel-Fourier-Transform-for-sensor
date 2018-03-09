#include "stdio.h"
#include "GFT_fn.h"

void generate_source(VALTYP2** source)
{
	VALTYP3 i;

	*source = (VALTYP2*)malloc(N_sample * sizeof(VALTYP2));
	for (i = 0; i<N_sample; i++)
	{
#ifdef FLOAT_VER
		**source = sin(5 * 2 * pi*i / Sampling_rate)*scale;
#endif
#ifdef FIXED_VER
		**source = (VALTYP2)(round(sin(5 * 2 * pi*i / Sampling_rate)*scale));
		if (llabs(**source) > upper_limit )
		{
			printf("i = %d, source is too large\n", i);
		}
		else if (llabs(**source) < lower_limit)
		{
			printf("i = %d, source is too small\n", i);
		}
#endif
		++(*source);
	}
	*source = *source - N_sample;
}