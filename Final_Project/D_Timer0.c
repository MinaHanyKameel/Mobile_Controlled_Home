/*
 * Timer0.c
 *
 *  Created on: Feb 15, 2019
 *      Author: Hanoon-PC
 */
#include "MACROS.h"
#include "TYPES.h"
#include "D_Timer0.h"

//OverFlow Mode
/*void Timer0_vidInint(void)
{
	//Waveform Generation Mode
	ClrBit(TCCR0,WGM01);
	ClrBit(TCCR0,WGM00);

	//Compare Output Mode
	ClrBit(TCCR0,COM01);
	ClrBit(TCCR0,COM00);

	//Clock Select Bit Description 1 0 0 clkI/O/256 (From prescaler)
	SetBit(TCCR0,CS02);
	ClrBit(TCCR0,CS01);
	ClrBit(TCCR0,CS00);

	//Timer/Counter0 Overflow Interrupt Enable
	SetBit(TIMSK,TOIE0);
}*/
//CTC Mode
void Timer0_vidInint(void)
{
	//Waveform Generation Mode Bit Description 1 1 Fast PWM
	SetBit(TCCR0,WGM01);
	SetBit(TCCR0,WGM00);

	//Compare Output Mode, Fast PWM Mode, Clear OC0 on compare match, set OC0 at TOP
	SetBit(TCCR0,COM01);
	ClrBit(TCCR0,COM00);

	//Clock Select Bit Description 0 0 1 clkI/O/(No prescaling)
	ClrBit(TCCR0,CS02);
	ClrBit(TCCR0,CS01);
	SetBit(TCCR0,CS00);

	//Timer/Counter0 CTC Interrupt Enable
	ClrBit(TIMSK,OCIE0);

}
u8 Tmer0_u8ReturnTimerRegister(void)
{
	return TCNT0;
}
void Timer0_vidSetOcr0(u8 u8OCR0)
{
	OCR0=u8OCR0;
}
