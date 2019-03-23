/*
 * HLCD.c
 *
 *  Created on: Jan 19, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"
#include "MACROS.h"
#include "H_LCD.h"

#include<util/delay.h>

#include "D_DIO.h"
#include "H_LCD_cfg.h"

extern void LCD_vidExecuteCommand(u8 Command)
{
	//RS=0
	DIO_vidWritePinValue(LCD_ControlPort,RS,LOW);
	//RW=0
	DIO_vidWritePinValue(LCD_ControlPort,RW,LOW);
	//load data
	DIO_vidWritePortValue(LCD_DataPort,Command);
	//EN=1
	DIO_vidWritePinValue(LCD_ControlPort,EN,HIGH);
	//delay 2 ms
	_delay_ms(2);
	//EN=0
	DIO_vidWritePinValue(LCD_ControlPort,EN,LOW);
}
extern void LCD_vidWriteData(u8 Data)
{
	//RS=1
	DIO_vidWritePinValue(LCD_ControlPort,RS,HIGH);
	//RW=0
	DIO_vidWritePinValue(LCD_ControlPort,RW,LOW);
	//load data
	DIO_vidWritePortValue(LCD_DataPort,Data);
	//EN=1
	DIO_vidWritePinValue(LCD_ControlPort,EN,HIGH);
	//delay 2 ms
	_delay_ms(2);
	//EN=0
	DIO_vidWritePinValue(LCD_ControlPort,EN,LOW);
	//_delay_ms(5);

}
extern void LCD_vidInit(void)
{

	DIO_vidSetPinDirection(LCD_ControlPort,RS,OUTPUT);
	DIO_vidSetPinDirection(LCD_ControlPort,RW,OUTPUT);
	DIO_vidSetPinDirection(LCD_ControlPort,EN,OUTPUT);
	DIO_vidSetPortDirection(LCD_DataPort,0xFF);
	_delay_ms(50);
	LCD_vidExecuteCommand(0b00111111);
	_delay_ms(2);
	LCD_vidExecuteCommand(0b00001110);
	_delay_ms(2);
	LCD_vidExecuteCommand(0b00000001);
	_delay_ms(2);
}
extern void LCD_vidClearDisplay(void)
{
	LCD_vidExecuteCommand(0b00000001);
}
extern void LCD_vidWriteString(u8* arr)
{
	u8 i=0;
	while(arr[i]!=0)
	{
		LCD_vidWriteData(arr[i]);
		i++;
	}
}

extern void LCD_vidWriteNumber(u32 Number)
{
	u32 Reversed = 1;
	if(Number==0)
	{
		LCD_vidWriteData('0');
	}
	while (Number!=0)
	{
		Reversed=((Reversed*10)+(Number%10));
		Number/=10;
	}
	while (Reversed!=1)
	{
		LCD_vidWriteData((Reversed%10)+48);
		Reversed/=10;
	}
}

extern void LCD_vidSetPosition (u8 Row,u8 Col)
{
	if(Row==1)
	{
		LCD_vidExecuteCommand(0x80+Col);
	}
	else
	{
		LCD_vidExecuteCommand(0x80+0x40+Col);
	}
}
