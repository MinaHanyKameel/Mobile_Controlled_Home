/*
 * ALogin.c
 *
 *  Created on: Mar 13, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"
#include "MACROS.h"
#include "A_Login.h"
#include "D_Internal_EEPROM.h"
#include "H_Bluetooth_UART.h"
#include "H_EEPROM.h"
#include "H_SignUp.h"

u8 Login_u8CheckUserNameAndPW(void)
{
	u8 Check=255;
	u8 i=0;
	u8 User1Status=NOTVALID;
	u8 User2Status=NOTVALID;
	u8 User3Status=NOTVALID;
	u8 Return=NOTVALID;
	u8 Block1=0;
	u8 Block2=0;
	u8 Block3=0;
	Bluetooth_vidInit();
	eeprom_init();
	Bluetooth_vidSendString((u8*)" ");
	Bluetooth_vidSendString((u8*)"Please Enter User Name : \n");
	Block1=0;
	Block2=0;
	Block3=0;
	Check=Bluetooth_u8Receive();
	while (Check!=' ')
	{
		Bluetooth_vidSend(Check);

		if(Check==eeprom_read_byte(User_1_ID_Address+i)&&Block1==0){User1Status=User1;}
		else {
			User1Status=NOTVALID;
			Block1=1;
		}

		if(Check==eeprom_read_byte(User_2_ID_Address+i)&&Block2==0){User2Status=User2;}
		else {
			User2Status=NOTVALID;
			Block2=1;
		}

		if(Check==eeprom_read_byte(User_3_ID_Address+i)&&Block3==0){User3Status=User3;}
		else {
			User3Status=NOTVALID;
			Block3=1;
		}

		i++;
		Check=Bluetooth_u8Receive();
	}
	Bluetooth_vidSendString((u8*)"Please Enter Password : \n");
	Check=Bluetooth_u8Receive();
	i=0;
	while (Check!=' ')
	{
		Bluetooth_vidSend(Check);
		if(Check==eeprom_read_byte(User_1_PW_Address+i)&&User1Status==User1&&Block1==0){Return=User1;}
		else
		{
			if(User1Status==User1){Return=NOTVALID;}
			User1Status=NOTVALID;
			Block1=1;
		}

		if(Check==eeprom_read_byte(User_2_PW_Address+i)&&User2Status==User2&&Block2==0){Return=User2;}
		else
		{
			if(User2Status==User2){Return=NOTVALID;}
			User2Status=NOTVALID;
			Block2=1;
		}

		if(Check==eeprom_read_byte(User_3_PW_Address+i)&&User3Status==User3&&Block3==0){Return=User3;}
		else
		{
			if(User3Status==User3){Return=NOTVALID;}
			User3Status=NOTVALID;
			Block3=1;
		}
		i++;
		Check=Bluetooth_u8Receive();
	}

	return Return;
}

u8 Login_u8LoginOperation(void)
{
	u8 Status=NOTVALID;
	u8 Return=NOTVALID;
	Status=Login_u8CheckUserNameAndPW();
	if(Status==User1)
	{
		Bluetooth_vidSendString((u8*)"\nWelcome ");
		Bluetooth_vidSendString((u8*)User_1_ID);
		Return=VALID;
	}
	else if(Status==User2)
	{
		Bluetooth_vidSendString((u8*)"\nWelcome ");
		Bluetooth_vidSendString((u8*)User_2_ID);
		Return=VALID;

	}
	else if(Status==User3)
	{
		Bluetooth_vidSendString((u8*)"Welcome ");
		Bluetooth_vidSendString((u8*)User_3_ID);
		Return=VALID;

	}
	else if(Status==NOTVALID)
	{
		Bluetooth_vidSendString((u8*)"Wrong User Name or PW Please Try Again ");
		Return=NOTVALID;
	}
	return Return;
}
//u8 Login_u8CheckUserNameAndPWinternalEEPROM(void)
//{
//	u8 Check=255;
//	u8 i=0;
//	u8 UserStatus=NOTVALID;
//	Bluetooth_vidInit();
//	Bluetooth_vidSendString((u8*)"Please Enter User Name");
//	Check=Bluetooth_u8Receive();
//
//	while (Check!='`')
//	{
//
//		Bluetooth_vidSend(Check);
//		if(Check==internalEEPROM_vidEEPROM_Read(0+i))
//		{
//			UserStatus=User1;
//			Bluetooth_vidSendString("ok");
//
//		}
//		else if(Check==internalEEPROM_vidEEPROM_Read(20+i))
//		{
//			UserStatus=User2;
//		}
//		else if(Check==internalEEPROM_vidEEPROM_Read(40+i))
//		{
//			UserStatus=User3;
//		}
//		else {
//			UserStatus=NOTVALID;
//			Bluetooth_vidSendString("notok");
//
//		}
//		Check=Bluetooth_u8Receive();
//
//		i++;
//	}
//	Bluetooth_vidSendString((u8*)"Please Enter Password");
//	Check=Bluetooth_u8Receive();
//
//	while (Check!='`')
//	{
//		Bluetooth_vidSend('*');
//		if(Check==internalEEPROM_vidEEPROM_Read(60+i)&&UserStatus==User1)
//		{
//			UserStatus=VALID;
//			Bluetooth_vidSendString("ok");
//		}
//		else if(Check==internalEEPROM_vidEEPROM_Read(80+i)&&UserStatus==User2)
//		{
//				UserStatus=VALID;
//		}
//		else if(Check==internalEEPROM_vidEEPROM_Read(100+i)&&UserStatus==User3)
//		{
//				UserStatus=VALID;
//		}
//		else {
//			UserStatus=NOTVALID;
//			Bluetooth_vidSendString("notok");
//
//		}
//		Check=Bluetooth_u8Receive();
//
//		i++;
//	}
//
//	return UserStatus;
//}
