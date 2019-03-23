/*
 * H_Servo_Motor.c
 *
 *  Created on: Mar 20, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"
#include "MACROS.h"
#include "D_Timer1.h"
#include "D_DIO.h"

void Servo_MotorvidInit(void)
{
	//Compare Output Mode, Fast PWM Clear OC1A/OC1B on compare match, set OC1A/OC1B at TOP
	Timer1_vidCompareOutputMode(1,0);

	//Waveform Generation Mode
	Timer1_vidTimer1Mode(1,1,1,0);

	//Clock Select Bit Description 1 0 0 clkI/O/256 (From prescaler)
	Timer1_vidSetPrescaler(1,0,0);

	//ICR1
	Timer1_VidSetICR1(625);
	Timer1_VidSetOCR1A(18);
	DIO_vidSetPinDirection(PORT_D,PIN5,OUTPUT);

}

void Servo_MotorvidSetAnglePercentage(u16 Num)
{
	Timer1_VidSetOCR1A(((Num*65)/100)+18);
}

