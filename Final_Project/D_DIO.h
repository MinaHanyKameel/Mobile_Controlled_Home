/*
 * DIO.h
 *
 *  Created on: Jan 12, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"

#ifndef DDIO_H_
#define DDIO_H_

#define DDRA *((volatile u8*)0x3A)
#define DDRB *((volatile u8*)0x37)
#define DDRC *((volatile u8*)0x34)
#define DDRD *((volatile u8*)0x31)

#define PORTA *((volatile u8*)0x3B)
#define PORTB *((volatile u8*)0x38)
#define PORTC *((volatile u8*)0x35)
#define PORTD *((volatile u8*)0x32)

#define PINA *((volatile u8*)0x39)
#define PINB *((volatile u8*)0x36)
#define PINC *((volatile u8*)0x33)
#define PIND *((volatile u8*)0x30)



#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0



extern void DIO_vidSetPinDirection(u8 port,u8 pin,u8 dir);

extern void DIO_vidWritePinValue(u8 port,u8 pin,u8 value);

extern u8 DIO_u8GetPinValue(u8 port,u8 pin);

extern void DIO_vidSetPortDirection(u8 port, u8 Dir);

extern void DIO_vidWritePortValue(u8 port, u8 value);




#endif /* DDIO_H_ */
