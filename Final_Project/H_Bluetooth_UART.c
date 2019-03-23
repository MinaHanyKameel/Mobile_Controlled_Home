/*
 * Bluetooth_UART.c
 *
 *  Created on: Mar 13, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"
#include "MACROS.h"

#include "H_Bluetooth_UART.h"

#include "util/delay.h"
#include "D_UART.h"

void Bluetooth_vidInit(void)
{
	UART_vidInit();
}

u8 Bluetooth_u8Receive(void)
{

	return UART_vidReceive();
}

void Bluetooth_vidSend(u8 Data)
{
	UART_vidSend(Data);
}

void Bluetooth_vidSendString(u8* Data)
{
	u8 i=0;
	UART_vidSend(' ');
	while(Data[i]!='\0')
	{
		UART_vidSend(Data[i]);
		i++;
	}
	return;
}

extern void Bluetooth_vidWriteNumber(u32 Number)
{
	u32 Reversed = 1;
	if(Number==0)
	{
		Bluetooth_vidSend('0');
	}
	while (Number!=0)
	{
		Reversed=((Reversed*10)+(Number%10));
		Number/=10;
	}
	while (Reversed!=1)
	{
		Bluetooth_vidSend((Reversed%10)+48);
		Reversed/=10;
	}
}
