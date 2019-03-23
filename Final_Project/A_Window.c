/*
 * A_Window.c
 *
 *  Created on: Mar 20, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"
#include "MACROS.h"

#include "H_Servo_Motor.h"
#include "H_Bluetooth_UART.h"

void Window_vidAngle(void)
{
	u16 Num=0;
	u8 STOP=0;
	u16 Get=0;
	Servo_MotorvidInit();
	while (STOP==0)
		{
			Bluetooth_vidSendString((u8*)"\nEnter Percentage of Opening\n");
			Num=0;
			Get=Bluetooth_u8Receive();
			while(Get!=' ')
			{
				switch(Get)
				{
				case '0':
				Num=(Num*10)+0;
				Bluetooth_vidSend('0');
				break;
				case '1':
				Num=(Num*10)+1;
				Bluetooth_vidSend('1');
				break;
				case '2':
				Num=(Num*10)+2;
				Bluetooth_vidSend('2');
				break;
				case '3':
				Num=(Num*10)+3;
				Bluetooth_vidSend('3');
				break;
				case '4':
				Num=(Num*10)+4;
				Bluetooth_vidSend('4');
				break;
				case '5':
				Num=(Num*10)+5;
				Bluetooth_vidSend('5');
				break;
				case '6':
				Num=(Num*10)+6;
				Bluetooth_vidSend('6');
				break;
				case '7':
				Num=(Num*10)+7;
				Bluetooth_vidSend('7');
				break;
				case '8':
				Num=(Num*10)+8;
				Bluetooth_vidSend('8');
				break;
				case '9':
				Num=(Num*10)+9;
				Bluetooth_vidSend('9');
				break;
				}
				Get=Bluetooth_u8Receive();
			}
			Servo_MotorvidSetAnglePercentage(Num);
			Bluetooth_vidSendString((u8*)"\nif you want to return to Menu Press ( @ ) \n");
			if(Bluetooth_u8Receive()=='@')
			{
				STOP=1;
			}
		}
}
