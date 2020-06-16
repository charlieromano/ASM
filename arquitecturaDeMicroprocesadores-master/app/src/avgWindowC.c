/*
 * avgWindowC.c
 *
 *  Created on: 15 sep. 2018
 *      Author: fsl
 */
#include "../inc/window.h"

uint16_t avgWindowC (int16_t *func1, uint8_t size, uint8_t n_samples, uint8_t delta_samples)
{
	if(delta_samples+n_samples>size)
		return 0;
	uint32_t accum=0;
	uint16_t avg=0;

	for(uint8_t i=0; i< n_samples; i++){
		accum += func1[delta_samples + i];
		if(accum>4294967295)
			accum=4294967295;
	}
	avg = (uint16_t)accum/n_samples;

	if(avg>65535)
		avg=65535;
	return avg;

}


