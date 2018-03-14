#include "GFT_fn.h"

void GoerFT(VALTYP2* GFT, VALTYP3 k, VALTYP2* source)
{
	VALTYP2 alpha;
	VALTYP2 v;
	VALTYP2 v_m1;
	VALTYP2 v_m2;
	VALTYP3 i;
	
	v = 0;
	v_m1 = 0;
	v_m2 = 0;

#ifdef FLOAT_VER
	alpha = 2 * cos((2 * pi*k) / N_SAMPLE)*scale_part;
	for (i = 0; i < N_SAMPLE; i++)
	{
		v = *(source)+alpha * v_m1 - v_m2;
		v_m2 = v_m1 * scale_part;
		v_m1 = v / scale_part;
		++source;
	}
	v_m2 = v_m2 / scale;
	*GFT = (v_m1*(v_m1 - alpha * v_m2) / scale) + v_m2 * v_m2;
	*GFT = ((*GFT) * 2) / N_SAMPLE;
#endif
#ifdef FIXED_VER
	genAlpha(&alpha, k);
	for (i = 0; i < N_SAMPLE; i++)
	{
		v = *(source) - alpha*v_m1 + 2*(v_m1 << scale_pow_part) - v_m2;
//		v = *(source) + alpha * v_m1 - v_m2;
		v_m2 = v_m1 << scale_pow_part;
		v_m1 = v >> scale_pow_part;
		++source;
	}
	v_m2 = v_m2 >> scale_pow;
	*GFT = (v_m1*(((v_m1 << (2 * scale_pow_part)) >> scale_pow) + alpha * v_m2) >> scale_pow);
	*GFT = *GFT + v_m2 * (v_m2 - (v_m1 >> (scale_pow - scale_pow_part - 1)));

//	*GFT = (v_m1*(((v_m1 << (2*scale_pow_part)) >> scale_pow)- alpha * v_m2) >> scale_pow) + v_m2 * v_m2;
	*GFT = ((*GFT) << 1) / N_SAMPLE;
#endif

	source = source - N_SAMPLE;
}
