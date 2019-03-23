/*
 * Timer0.h
 *
 *  Created on: Feb 15, 2019
 *      Author: Hanoon-PC
 */

#ifndef D_TIMER0_H_
#define D_TIMER0_H_

//Timer/Counter Control Register – TCCR0

#define TCCR0 *((volatile u8*)0x53)

#define CS00 PIN0
#define CS01 PIN1
#define CS02 PIN2
#define WGM01 PIN3
#define COM00 PIN4
#define COM01 PIN5
#define WGM00 PIN6
#define FOC0 PIN7

//Timer/Counter Register – TCNT0
#define TCNT0 *((volatile u8*)0x52)

//Output Compare Register – OCR0
#define OCR0 *((volatile u8*)0x5c)

//Timer/Counter Interrupt Mask Register – TIMSK

#define TIMSK *((volatile u8*)0x59)

#define TOIE0 PIN0
#define OCIE0 PIN1

//Timer/Counter Interrupt Flag Register – TIFR
#define TIFR *((volatile u8*)0x58)

#define TOV0 PIN0
#define OCF0 PIN1



u8 Tmer0_u8ReturnTimerRegister(void);

void Timer0_vidInint(void);

void Timer0_vidSetOcr0(u8 u8OCR0);



#endif /* D_TIMER0_H_ */
