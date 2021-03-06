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

#ifndef _SUMA_H_
#define _SUMA_H_

/*==================[inclusions]=============================================*/
#include <stdint.h>

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/**
 * Funcion que suma dos enteros de 32 bits y devuelve el resultado
 * @param firstOperand primer sumando
 * @param secondOperand segundo sumando
 * @return suma
 */
extern uint32_t asmSum(uint32_t firstOperand, uint32_t secondOperand);
extern uint32_t CSum(uint32_t firstOperand, uint32_t secondOperand);

extern void zeros (uint32_t * vector, uint32_t longitud);
extern void productoEscalar32 (uint32_t * vectorIn, uint32_t * vectorOut, uint32_t longitud, uint32_t escalar);
extern void echo (int16_t* vectorIn, int16_t* vectorOut, int16_t longitud, int16_t echo_time);
extern void echo2 (int16_t* vectorIn, int16_t* vectorOut, int16_t longitud, int16_t echo_time);
extern void avgDifference(uint8_t * vecIn, uint8_t * vecOut, uint32_t length);
extern void invertir (uint16_t * vector, uint32_t longitud);

extern void corrC  (int16_t *vectorX, int16_t * vectorY, int16_t *vectorCorr, uint32_t longitud);
extern void convC  (int16_t *vectorX, int16_t * vectorY, int16_t *vectorCorr, uint32_t longitud);
extern void corrASM(int16_t *vectorX, int16_t * vectorY, int16_t *vectorCorr, uint32_t longitud);
extern void sumaSIMD(int16_t *vectorX, int16_t * vectorY, int16_t *vectorCorr, uint32_t longitud);
extern void productoSIMD(int16_t *vectorX, int16_t * vectorY, int16_t *vectorCorr, uint32_t longitud);

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef _MAIN_H_ */
