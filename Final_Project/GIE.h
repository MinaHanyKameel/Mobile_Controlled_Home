/*
 * GIE_reg.h
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */

#ifndef GIE_H_
#define GIE_H_

void GIE_EnableGlobalInterrupt(void);

void GIE_DisableGlobalInterrupt(void);


#define SREG *((volatile u8*) 0x5F)

#endif /* GIE_H_ */
