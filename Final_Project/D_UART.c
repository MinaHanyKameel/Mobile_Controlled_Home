/*
 * UART.c
 *
 *  Created on: Feb 23, 2019
 *      Author: Hanoon-PC
 */

#include "TYPES.h"
#include "MACROS.h"
#include "D_UART.h"


void UART_vidInit(void)
{
	SetBit(UCSRB,RXEN);
	SetBit(UCSRB,TXEN);

//	SetBit(UCSRC,URSEL);
//
//	ClrBit(UCSRC,UMSEL);
//
//	ClrBit(UCSRC,UPM1);
//	ClrBit(UCSRC,UPM0);
//
//	ClrBit(UCSRC,USBS);
//
	ClrBit(UCSRB,UCSZ2);
//	SetBit(UCSRC,UCSZ1);
//	SetBit(UCSRC,UCSZ0);

	UCSRC=0b10000110;
	ClrBit(UCSRA,U2X);
//	ClrBit(UBRRH,URSEL);
//	ClrBit(UBRRH,PIN0);
//	ClrBit(UBRRH,PIN1);
//	ClrBit(UBRRH,PIN2);
//	ClrBit(UBRRH,PIN3);
	UBRRH=0;
	UBRRL=51;

}

u8 UART_vidReceive(void)
{
	while(GetBit(UCSRA,RXC)==0);
	return UDR ;
}

void UART_vidSend(u8 DATA)
{
	UDR=DATA;
	while(GetBit(UCSRA,UDRE)==0);
}
