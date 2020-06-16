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

#include "examen.h"
#include "board.h"

/*==================[macros and definitions]=================================*/
#define WIDTH 	4
#define HEIGTH 	4
#define MAX_UINT_12_BITS 4095

/*==================[internal data declaration]==============================*/
volatile uint32_t * DWT_CTRL   = (uint32_t *)0xE0001000;
volatile uint32_t * DWT_CYCCNT = (uint32_t *)0xE0001004;

/*==================[internal functions declaration]=========================*/

/** @brief hardware initialization function
 *  @return none
 */
static void initHardware(void);

/*==================[internal data definition]===============================*/

uint16_t image[WIDTH][HEIGTH];

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
    volatile uint32_t cyclesC=0,
    				  cyclesAsm=0,
					  cyclesSIMD=0;
    volatile uint32_t i, j,
			avgImageResultC,
			avgImageResultAsm,
			avgImageResultSimd;

    initHardware();

    //Inicializacion de la imagen
    for (i=0; i < WIDTH; i++)
    {
    	for (j=0; j < HEIGTH; j++)
    	{
    		// Todos los elementos = 4095 -> (2^12) -1
    		image[i][j] = MAX_UINT_12_BITS;

    		//Valores diferentes
    		//image[i][j] = (i+j) % (MAX_UINT_12_BITS+1);  //Usamos modulo 4096 para no pasarnos de 12 bits
    	}
    }

    /*
     * Activamos el conteo de ciclos.
     * Hacemos una OR de bits con el valor 1.
     */
    *DWT_CTRL  |= 1;


    //Función en C
    *DWT_CYCCNT = 0;
    avgImageResultC = avgImageC((uint16_t *) image, WIDTH, HEIGTH);
    cyclesC=*DWT_CYCCNT;

     //Funcion ASM tradicional
    *DWT_CYCCNT = 0;
    avgImageResultAsm = avgImageAsm((uint16_t *) image, WIDTH, HEIGTH);
    cyclesAsm=*DWT_CYCCNT;


    //Funcion asm con SIMD
    *DWT_CYCCNT = 0;
    avgImageResultSimd = avgImageSIMD((uint16_t *) image, WIDTH, HEIGTH);
    cyclesSIMD=*DWT_CYCCNT;



    while (1)
    {
        __WFI(); //wfi
    }
}

/** @} doxygen end group definition */

/*==================[end of file]============================================*/
