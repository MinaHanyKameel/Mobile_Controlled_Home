/*
 * Project_App.c
 *
 *  Created on: Mar 13, 2019
 *      Author: Hanoon-PC
 */
#include "util/delay.h"
#include "TYPES.h"
#include "MACROS.h"
#include "H_PWM_LightIntensity.h"
#include "Project_App.h"
#include "A_LightIntensity.h"
#include "A_Login.h"
#include "A_Menu.h"
#include "A_TempStatus.h"
#include "H_Bluetooth_UART.h"
#include "H_EEPROM.h"
#include "H_SignUp.h"
#include "A_Window.h"

int main (void)
{
	u8 State=LogIn;
	Bluetooth_vidInit();
	SignUP_vidInit();
	while(1)
	{
		switch (State){
		case LogIn:
			if(Login_u8LoginOperation()==VALID){State = Menu;}
			else{State = LogIn;}
			break;
		case Menu:
			State = AMenu_u8Amenu();
			break;
		case LightIntesity:
			LightIntensity_vidControl();
			State=Menu;
			break;
		case TempStatus:
			TempStatus_vidTempStatus();
			State=Menu;
			break;
		case WindowAngle:
			Window_vidAngle();
			State=Menu;
			break;
		default:
			State=Menu;
			break;
		}
	}
	return 1;
}
