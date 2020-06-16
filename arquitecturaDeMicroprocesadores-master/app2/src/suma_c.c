/*
 * suma.c
 *
 *  Created on: 15 sep. 2018
 *      Author: fsl
 */
#include <suma.h>
#include <stdio.h>

uint32_t CSum(uint32_t firstOperand, uint32_t secondOperand)
{
	return firstOperand+secondOperand;
}


void convC(int16_t *vectorX, int16_t * vectorY, int16_t* vectorCorr, uint32_t longitud){

	int32_t N = longitud;
	int16_t y2[longitud];

	for(uint32_t i=0; i<longitud; i++)
		y2[i]=0;

	for(uint32_t l=0; l< 2*N-1; l++){
		for(uint32_t n=0; n<N ; n++){
			int i = n-l;
			if((n>l)||(i<-N+1))
				y2[n] = 0;
			else
				y2[n] = vectorY[l-n];
			vectorCorr[l] += vectorX[n]*y2[n];
		}
	}


}

void corrC(int16_t *vectorX, int16_t * vectorY, int16_t* vectorCorr, uint32_t longitud){

	int32_t N = longitud;
	int16_t y2[longitud];

	for(uint32_t i=0; i<longitud; i++)
		y2[i]=0;

	for(uint32_t l=0; l< 2*N-1; l++){
		for(uint32_t n=0; n<N ; n++){
			int i = n-l+N-1;
			if((i<0)||(i>N-1))
				y2[n] = 0;
			else
				y2[n] = vectorY[i];
			vectorCorr[l] += vectorX[n]*y2[n];
		}
	}
}


