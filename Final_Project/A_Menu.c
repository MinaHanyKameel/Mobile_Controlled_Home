/*
 * AMenu.c
 *
 *  Created on: Mar 20, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"
#include "MACROS.h"
#include "H_Bluetooth_UART.h"
#include "Project_App.h"

u8 AMenu_u8Amenu(void)
{
	u8 State;
	volatile u8 u8Receive='0';

	Bluetooth_vidSendString((u8*)"\nPlease Enter a choice of these: ");
	Bluetooth_vidSendString((u8*)"\n1- Control Light Intensity  \n2- Temperature Status on LCD  \n3- Window angle control \n");
	u8Receive=Bluetooth_u8Receive();
	if('1'==u8Receive)
	{
		State = LightIntesity;
	}
	else if('2'==u8Receive)
	{
		State = TempStatus;
	}
	else if('3'==u8Receive)
	{
		State = WindowAngle;
	}
	else {
		Bluetooth_vidSendString((u8*)"\nEnter Valid Number\n");
		State = Menu;
	}
	return State;
}
