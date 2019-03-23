/*
 * HLCD.h
 *
 *  Created on: Jan 19, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"

#ifndef HLCD_H_
#define HLCD_H_

extern void LCD_vidExecuteCommand(u8 Command);

extern void LCD_vidWriteData(u8 Data);

extern void LCD_vidInit(void);

extern void LCD_vidClearDisplay(void);

extern void LCD_vidWriteString(u8 * arr);

extern void LCD_vidWriteNumber(u32 Number);

extern void LCD_vidSetPosition (u8 Row,u8 Col);

#endif /* HLCD_H_ */
