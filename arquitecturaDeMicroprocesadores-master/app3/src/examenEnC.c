#include "../inc/examen.h"

/* TIP: acceder a la imagen como si fuera un vector: image[indice] */
uint32_t avgImageC (uint16_t * image, uint8_t n, uint8_t m)
{
	uint32_t avg =0;
	uint32_t accum2 =0;

	for(uint8_t j=0; j<m; j++){
		uint32_t accum =0;

		for(uint8_t i=0; i<n; i++){
			accum+= image[i+j*n];
			if(accum>4294967295)
				accum=4294967295;
		}
		accum2 += accum/n;
	}
	avg = accum2/m;

	return avg;
}
