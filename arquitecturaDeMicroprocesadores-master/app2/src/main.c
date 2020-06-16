/* Copyright 2018, Facundo Larosa - Danilo Zecchin
 * All rights reserved.
 *
 * This file is part of arquitecturaDeMicroprocesadores.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
 
/** @brief This is a simple blink example.
 */

/** \addtogroup blink Bare-metal blink example
 ** @{ */

/*==================[inclusions]=============================================*/

#include "main.h"
#include "board.h"
#include "suma.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/** @brief hardware initialization function
 *	@return none
 */
static void initHardware(void);

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

static void initHardware(void)
{
	Board_Init();
	SystemCoreClockUpdate();
	//SysTick_Config(SystemCoreClock / 1000);
}

/*==================[external functions definition]==========================*/

volatile uint32_t * DWT_CTRL = (uint32_t *)0xE0001000;
volatile uint32_t * DWT_CYCCNT = (uint32_t *)0xE0001004;
uint32_t Ciclos_ASM=0;
uint32_t Ciclos_C=0;

int main(void)
{
	volatile  uint32_t aValue = 20,
			 otherValue = 30,
			 sumResult_Asm,sumResult_C;

	initHardware();
	*DWT_CTRL  |= 1;
	 SystemCoreClockUpdate();

	//sumResult_C= CSum(aValue,otherValue);
	//sumResult_Asm = asmSum(aValue, otherValue);

  /** Ejercicio 1 **************************************************/
	// creo el vector
	//uint32_t v[5] = {4,5,2,6,2};

  // llamo a la funcion
  //zeros(v,5);

  /*****************************************************************/

  /** Ejercicio 2 **************************************************/
  //uint32_t longitud=10;
  //uint32_t escalar=2;
  //uint32_t vector_in[10]={1,1,1,1,1,3,3,3,3,3};
  //uint32_t vector_out[10]={0,0,0,0,0,0,0,0,0,0};

  //productoEscalar32(vector_in, vector_out, longitud, escalar);

  /*****************************************************************/

  /** Ejercicio 9**************************************************/

  //uint16_t v9[5] = {1,2,3,4,5};
  //invertir(v9,5);

  /*****************************************************************/

  /** Ejercicio 10  ************************************************/
/*
  int16_t vi_10[16] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
  int16_t vo_10[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int16_t longitud_10 = 16;
  int16_t echo_time = 4;

  echo2(vi_10, vo_10, longitud_10, echo_time );
*/

/*****************************************************************/

	uint32_t longitud = 4;
	int16_t vi[4]	={-3,2,-1,1};
	int16_t vo[4]	={-1,0,-3,2};
	int16_t corr[2*4-1]={0,0,0,0,0,0,0};

	//convC(vi,vo, corr, longitud);
	*DWT_CYCCNT=0;
	//corrASM(vi,vo, corr, longitud);
	sumaSIMD(vi,vo, corr, longitud);
	Ciclos_C=*DWT_CYCCNT;
	//avgDifference(vi, vo, len);


  /*****************************************************************/

	while (1)
	{
		__WFI(); //wfi
	}
}

/** @} doxygen end group definition */

/*==================[end of file]============================================*/
