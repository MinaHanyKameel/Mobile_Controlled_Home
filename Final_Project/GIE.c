/*
 * GIE.c
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */
#include "TYPES.h"
#include "MACROS.h"
#include "GIE.h"


void GIE_EnableGlobalInterrupt(void)
{
	SetBit(SREG,7);
}

void GIE_DisableGlobalInterrupt(void)
{
	ClrBit(SREG,7);
}
