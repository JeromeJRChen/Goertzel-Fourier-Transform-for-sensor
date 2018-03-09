//#include "stdio.h"
#include "GFT_fn.h"

void effi_check(VALTYP3 n)
{
	VALTYP3 power;
	VALTYP3 M;

	power = round((log(N_sample) / log(2.)));
	M = round((5.*(1 << power)) / (6.*N_sample)*power);
	if (M <= n)
	{
//		printf("\nThe times of Goertzel method is n_GA = %d.", n_GA);
//		printf("\nIt should be less than M = %d.\n", M);
//		printf("Suggest using Fast Fourier transform.\n");
	}
}
