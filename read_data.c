#include <stdio.h>
#include "GFT_fn.h"

void read_data(VALTYP2** source)
{
	VALTYP3 i;
	VALTYP1 tmp1 = 0.;
	VALTYP1 tmp2 = 0.;
	FILE *stream;
	stream = fopen("file.txt", "r");
	if (stream == NULL)
	{
		printf("¶}±ÒÀÉ®×¥¢±Ñ¡AGG!!\n");
		exit(0);
	}
	else
	{
		fscanf(stream, "%d", &N_sample);
		*source = (VALTYP2*)malloc(N_sample * sizeof(VALTYP2));
		fscanf(stream, "%d", &Sampling_rate);
		for (i = 0; i < N_sample; i++)
		{
#ifdef FLOAT_VER
			fscanf(stream, "%lf%lf", &tmp1, *source);
#endif
#ifdef FIXED_VER
			fscanf(stream, "%15lf%18lf", &tmp1, &tmp2);
			**source = (VALTYP2)(round(tmp2*scale));
#endif
			++(*source);
		}
		*source = *source - N_sample;
	}
	fclose(stream);
}