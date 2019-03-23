/*
 * DInternal_EEPROM.c
 *
 *  Created on: Mar 14, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"
#include "MACROS.h"
#include "D_Internal_EEPROM.h"

#include "util/delay.h"

void internalEEPROM_vidEEPROM_Write(u16 Address, u8 Data)
{
	/* Wait for completion of previous write */
	while (GetBit(EECR,EEWE)==1);
//	while(EECR & (1<<EEWE));

	while (GetBit(SPMCR,SPMEN)==1);

	/* Set up address and data registers */
	EEAR = Address;
	EEDR = Data;

	/* Write logical one to EEMWE */
	SetBit(EECR,EEMWE);
//	EECR |= (1<<EEMWE);
	_delay_ms(1);
	/* Start eeprom write by setting EEWE */
	ClrBit(EECR,EEWE);
	_delay_ms(1);

//	EECR |= (1<<EEWE);
	SetBit(EECR,EEWE);
	_delay_ms(1);

}

u8 internalEEPROM_vidEEPROM_Read(u16 Address)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address register */
	EEAR = Address;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}

void internalEEPROM_vidEEPROM_WriteString(u16 Address, u8* Data)
{
	volatile u8 i=0;
	while(Data[i]!='\0')
	{
		internalEEPROM_vidEEPROM_Write(Address+i,Data[i]);
		i++;
	}
	internalEEPROM_vidEEPROM_Write(Address+i+1,0xFF);
	return;
}

void internalEEPROM_vidEEPROM_ReadString(u16 Address, u8* Data)
{
	volatile u8 i=0;
	while(internalEEPROM_vidEEPROM_Read(Address+i)!=0xFF)
	{
		Data[i]=internalEEPROM_vidEEPROM_Read(Address+i);
		i++;
	}
	return;
}
