#include "GFT_fn.h"

void band_width(VALTYP2* sum, VALTYP2* source, VALTYP1 Target_freq, VALTYP1 beam_width)
{
	VALTYP1 ratio = (VALTYP1)(N_sample - 1) / Sampling_rate;
	VALTYP1 dif = beam_width / 2 * ratio;
	VALTYP1 mid = Target_freq * ratio;
	VALTYP3 k_m = round(mid - dif);
	VALTYP3 k_p = round(mid + dif);
	VALTYP3 k;
	VALTYP2 GFT = 0;

	*sum = 0;
	for (k = k_m; k <= k_p; k++)
	{
		GoerFT(&GFT, k, source);
		*sum = *sum + GFT;
	}
	*sum = *sum / (k_p - k_m + 1);
}