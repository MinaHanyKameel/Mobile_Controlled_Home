/*
 * DInternal_EEPROM.h
 *
 *  Created on: Mar 14, 2019
 *      Author: Hanoon-PC
 */

#ifndef D_INTERNAL_EEPROM_H_
#define D_INTERNAL_EEPROM_H_

//The EEPROM Address Register – EEARH and EEARL
#define EEAR *((u16*)0x3E)

//The EEPROM Data Register – EEDR
#define EEDR *((u8*)0x3D)

//The EEPROM Control Register – EECR
#define EECR *((u8*)0x3C)
#define EERIE PIN3
#define EEMWE PIN2
#define EEWE PIN1
#define EERE PIN0

//
#define SPMCR *((u8*)0x57)
#define SPMIE PIN7
#define RWWSB PIN6
#define RWWSRE PIN4
#define BLBSET PIN3
#define PGWRT PIN2
#define PGERS PIN1
#define SPMEN PIN0

void internalEEPROM_vidEEPROM_Write(u16 Address, u8 Data);
u8 internalEEPROM_vidEEPROM_Read(u16 Address);
void internalEEPROM_vidEEPROM_WriteString(u16 Address, u8* Data);
void internalEEPROM_vidEEPROM_ReadString(u16 Address, u8* Data);


#endif /* D_INTERNAL_EEPROM_H_ */
