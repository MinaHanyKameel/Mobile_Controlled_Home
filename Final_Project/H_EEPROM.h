#ifndef H_EEPROM_H_
#define H_EEPROM_H_

#include "D_I2C.h"

void eeprom_init(void);
void eeprom_write_byte(unsigned short address, unsigned char data);
unsigned char eeprom_read_byte(unsigned short address);

void EEPROM_vidEEPROM_ReadString(u16 Address, u8* Data);

void EEPROM_vidEEPROM_WriteString(u16 Address, u8* Data);

#endif /* H_EEPROM_H_ */
