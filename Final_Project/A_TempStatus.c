/*
 * ATempStatus.c
 *
 *  Created on: Mar 18, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"
#include "MACROS.h"
#include "D_ADC.h"
#include "H_Bluetooth_UART.h"
#include "util/delay.h"
#include "H_LCD.h"

void TempStatus_vidTempDisplayInit(void)
{
	f32 Result=0;
	Result=0;
	ADC_vidInit();
	Result=(ADC_vidReturnResult()*60*5.0*1000.0)/1023.0;
//	Bluetooth_vidWriteNumber((u32)Result/1000);
//	Bluetooth_vidSendString((u8*)".");
//	Bluetooth_vidWriteNumber((u32)Result%1000);
//	Bluetooth_vidSendString((u8*)" V        ");

	if(((u32)Result/1000)>=150)
	{
		Bluetooth_vidWriteNumber((((u32)Result)/1000)-150);
		Bluetooth_vidSendString((u8*)".");
		Bluetooth_vidWriteNumber(((u32)Result)%1000);
		Bluetooth_vidSendString((u8*)" C        ");
	}
	else if(((u32)Result/1000)<150)
	{
		Bluetooth_vidSend('-');
		Bluetooth_vidWriteNumber(150-((u32)Result)/1000);
		Bluetooth_vidSendString((u8*)".");
		Bluetooth_vidWriteNumber(((u32)Result)%1000);
		Bluetooth_vidSendString((u8*)" C        ");
	}
}

void TempStatus_vidTempStatus(void)
{
	u8 check=0;
	while(check!=' '){
	Bluetooth_vidSendString((u8 *)"\n");
	TempStatus_vidTempDisplayInit();
	Bluetooth_vidSendString((u8 *)"\nTo exit press space and to continue press any key\n");
	check = Bluetooth_u8Receive();
	}
	check=0;
}
