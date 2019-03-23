/*
 * Timer0.h
 *
 *  Created on: Feb 15, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"
#ifndef TIMER0_H_
#define TIMER0_H_

//Timer/Counter1 Control Register A – TCCR1A

#define TCCR1A *((volatile u8*)0x4F)

#define WGM10 PIN0
#define WGM11 PIN1
#define FOC1B PIN2
#define FOC1A PIN3
#define COM1B0 PIN4
#define COM1B1 PIN5
#define COM1A0 PIN6
#define COM1A1 PIN7

//Timer/Counter1 Control Register B – TCCR1B

#define TCCR1B *((volatile u8*)0x4E)

#define CS10 PIN0
#define CS11 PIN1
#define CS12 PIN2
#define WGM12 PIN3
#define WGM13 PIN4
//PIN5 Reserved
#define ICES1 PIN6
#define ICNC1 PIN7

//Timer/Counter1 – TCNT1H and TCNT1L
#define TCNT1H *((volatile u8*)0x4D)
#define TCNT1L *((volatile u8*)0x4C)
		/*The 2 Bytes Register*/
#define TCNT1 *((volatile u16*)0x4C)

//Output Compare Register 1 A – OCR1AH and OCR1AL
#define OCR1AH *((volatile u8*)0x4B)
#define OCR1AL *((volatile u8*)0x4A)
		/*The 2 Bytes Register*/
#define OCR1A *((volatile u16*)0x4A)

//Output Compare Register 1 B – OCR1BH and OCR1BL
#define OCR1BH *((volatile u8*)0x49)
#define OCR1BL *((volatile u8*)0x48)
		/*The 2 Bytes Register*/
#define OCR1B *((volatile u16*)0x48)

//Input Capture Register 1 – ICR1H and ICR1L
#define ICR1H *((volatile u8*)0x47)
#define ICR1L *((volatile u8*)0x46)
		/*The 2 Bytes Register*/
#define ICR1 *((volatile u16*)0x46)

//Timer/Counter Interrupt Mask Register – TIMSK
#ifndef TIMSK
#define TIMSK *((volatile u8*)0x59)
#endif

#define TOIE1 PIN2
#define OCIE1B PIN3
#define OCIE1A PIN4
#define TICIE1 PIN5

//Timer/Counter Interrupt Flag Register – TIFR
#ifndef TIFR
#define TIFR *((volatile u8*)0x58)
#endif

#define TOV1 PIN2
#define OCF1B PIN3
#define OCF1A PIN4
#define ICF1 PIN5

void Timer1_vidInint(void);

void Timer1_vidSetPrescaler(u8 u8CS12,u8 u8CS11,u8 u8CS10);

void Timer1_vidCompareOutputMode(u8 u8COM1A1,u8 u8COM1A0);

void Timer1_VidSetICR1(u16 u16ICR1);

void Timer1_vidTimer1Mode(u8 u8WGM13, u8 u8WGM12 , u8 u8WGM11, u8 u8WGM10);

void Timer1_VidSetOCR1A(u16 u16OCR1A);


#endif /* TIMER1_H_ */
