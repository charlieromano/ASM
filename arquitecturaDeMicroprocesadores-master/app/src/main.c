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

#include "../inc/window.h"
#include "board.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/
volatile uint32_t * DWT_CTRL   = (uint32_t *)0xE0001000;
volatile uint32_t * DWT_CYCCNT = (uint32_t *)0xE0001004;
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

int main(void)
{
	volatile uint32_t cyclesC=0,cyclesAsm=0,cyclesSIMD=0;
	volatile int32_t resultC=0,resultAsm=0,resultSIMD=0, i;
	uint16_t func[ARRAY_SIZE];
	uint8_t n_samples=24,delta_samples=4;
	volatile uint16_t resultados[2]={0,0};

	initHardware();

    /* Se inicializa el array func con valores de 0 a ARRAY_SIZE */
	for(i=0;i<ARRAY_SIZE;i++)
		func[i]=i;

	*DWT_CTRL  |= 1;

	*DWT_CYCCNT = 0;
	resultC=avgWindowC (func, ARRAY_SIZE, n_samples, delta_samples);
	cyclesC=*DWT_CYCCNT;

	resultados[0]= resultC;

	*DWT_CYCCNT = 0;
	resultAsm=avgWindowAsm (func, ARRAY_SIZE, n_samples, delta_samples);
	cyclesAsm=*DWT_CYCCNT;

	resultados[1]= resultAsm;

	*DWT_CYCCNT = 0;
	resultSIMD=avgWindowSIMD (func, ARRAY_SIZE, n_samples, delta_samples);
	cyclesSIMD=*DWT_CYCCNT;

	while (1)
	{
		Board_LED_Toggle(LED);
		__WFI(); //wfi
	}
}

/** @} doxygen end group definition */

/*==================[end of file]============================================*/
