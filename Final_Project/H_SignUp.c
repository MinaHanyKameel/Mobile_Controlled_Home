/*
 * ASignUp.c
 *
 *  Created on: Mar 14, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"
#include "MACROS.h"
#include "H_SignUp.h"
#include "H_EEPROM.h"

void SignUP_vidInit(void)
{
//	internalEEPROM_vidEEPROM_WriteString(User_1_ID_Address,(u8*)User_1_ID);
//	internalEEPROM_vidEEPROM_WriteString(User_1_PW_Address,(u8*)User_1_PW);
//	internalEEPROM_vidEEPROM_WriteString(User_2_ID_Address,(u8*)User_2_ID);
//	internalEEPROM_vidEEPROM_WriteString(User_2_PW_Address,(u8*)User_2_PW);
//	internalEEPROM_vidEEPROM_WriteString(User_3_ID_Address,(u8*)User_3_PW);
//	internalEEPROM_vidEEPROM_WriteString(User_3_PW_Address,(u8*)User_3_PW);

	EEPROM_vidEEPROM_WriteString(User_1_ID_Address,(u8*)User_1_ID);
	EEPROM_vidEEPROM_WriteString(User_1_PW_Address,(u8*)User_1_PW);
	EEPROM_vidEEPROM_WriteString(User_2_ID_Address,(u8*)User_2_ID);
	EEPROM_vidEEPROM_WriteString(User_2_PW_Address,(u8*)User_2_PW);
	EEPROM_vidEEPROM_WriteString(User_3_ID_Address,(u8*)User_3_ID);
	EEPROM_vidEEPROM_WriteString(User_3_PW_Address,(u8*)User_3_PW);

}
