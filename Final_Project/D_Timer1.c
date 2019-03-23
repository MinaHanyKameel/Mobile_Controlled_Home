/*
 * Timer0.c
 *
 *  Created on: Feb 15, 2019
 *      Author: Hanoon-PC
 */

#include "TYPES.h"
#include "MACROS.h"
#include "D_Timer1.h"


void Timer1_vidInint(void)
{
//	//Compare Output Mode, Fast PWM Clear OC1A/OC1B on compare match, set OC1A/OC1B at TOP
//	SetBit(TCCR1A,COM1A1);
//	ClrBit(TCCR1A,COM1A0);
	Timer1_vidCompareOutputMode(1,0);

//	//Waveform Generation Mode
//	SetBit(TCCR1B,WGM13);
//	SetBit(TCCR1B,WGM12);
//	SetBit(TCCR1A,WGM11);
//	ClrBit(TCCR1A,WGM10);
	Timer1_vidTimer1Mode(1,1,1,0);

//	//Clock Select Bit Description 1 0 0 clkI/O/256 (From prescaler)
//	SetBit(TCCR1B,CS12);
//	ClrBit(TCCR1B,CS11);
//	ClrBit(TCCR1B,CS10);
	Timer1_vidSetPrescaler(1, 0, 0);

}
void Timer1_VidSetICR1(u16 u16ICR1)
{
	ICR1=u16ICR1;
}
void Timer1_VidSetOCR1A(u16 u16OCR1A)
{
	OCR1A=u16OCR1A;
}
void Timer1_vidSetPrescaler(u8 u8CS12,u8 u8CS11,u8 u8CS10)
{
	switch (u8CS12){
	case 0: ClrBit(TCCR1B,CS12);
	break;
	case 1: SetBit(TCCR1B,CS12);
	break;
	}
	switch (u8CS11){
	case 0: ClrBit(TCCR1B,CS11);
	break;
	case 1: SetBit(TCCR1B,CS11);
	break;
	}
	switch (u8CS10){
	case 0: ClrBit(TCCR1B,CS10);
	break;
	case 1: SetBit(TCCR1B,CS10);
	break;
	}

}
void Timer1_vidCompareOutputMode(u8 u8COM1A1,u8 u8COM1A0)
{
	switch (u8COM1A1){
	case 0: ClrBit(TCCR1A,COM1A1);
	break;
	case 1: SetBit(TCCR1A,COM1A1);
	break;
	}
	switch (u8COM1A0){
	case 0: ClrBit(TCCR1A,COM1A0);
	break;
	case 1: SetBit(TCCR1A,COM1A0);
	break;
	}


}
void Timer1_vidTimer1Mode(u8 u8WGM13, u8 u8WGM12 , u8 u8WGM11, u8 u8WGM10)
{
		switch (u8WGM13){
	case 0: ClrBit(TCCR1B,WGM13);
	break;
	case 1: SetBit(TCCR1B,WGM13);
	break;
	}
	switch (u8WGM12){
	case 0: ClrBit(TCCR1B,WGM12);
	break;
	case 1: SetBit(TCCR1B,WGM12);
	break;
	}
	switch (u8WGM11){
	case 0: ClrBit(TCCR1A,WGM11);
	break;
	case 1: SetBit(TCCR1A,WGM11);
	break;
	}
	switch (u8WGM10){
	case 0: ClrBit(TCCR1A,WGM10);
	break;
	case 1: SetBit(TCCR1A,WGM10);
	break;
	}
}
