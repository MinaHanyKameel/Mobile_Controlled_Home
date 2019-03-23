/*
 * ADC.c
 *
 *  Created on: Feb 9, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"
#include "MACROS.h"
#include "D_ADC.h"

void ADC_vidInit(void)
{
	/*AVCC with external capacitor at AREF pin*/
	ClrBit(ADMUX,REFS1);
	SetBit(ADMUX,REFS0);
	/*ADC Data Register Left Adjust*/
	//SetBit(ADMUX,ADLAR);
	/*ADC Data Register Right Adjust*/
	ClrBit(ADMUX,ADLAR);
	/*ADC0 - Single Ended Input*/
	ClrBit(ADMUX,MUX0);
	ClrBit(ADMUX,MUX1);
	ClrBit(ADMUX,MUX2);
	ClrBit(ADMUX,MUX3);
	ClrBit(ADMUX,MUX4);
	/*ADC Enable*/
	SetBit(ADCSRA,ADEN);
//	/*ADC Start Conversion in Single Conversion Mode*/
//	SetBit(ADCSRA,ADSC);
	/*ADC Auto Trigger Enable*/
	ClrBit(ADCSRA,ADATE);
	/*ADC Interrupt Enable*/
	ClrBit(ADCSRA,ADIE);

	/*
	 * ADC Prescaler Selections
		ADPS2 ADPS1 ADPS0 Division Factor
		0	  0 	0 	  2
		0 	  0 	1 	  2
		0 	  1 	0 	  4
		0 	  1 	1 	  8
		1  	  0 	0 	 16
		1 	  0 	1 	 32
		1 	  1  	0 	 64
		1 	  1 	1 	128
	 * */
	SetBit(ADCSRA,ADPS2);
	SetBit(ADCSRA,ADPS1);
	SetBit(ADCSRA,ADPS0);
}

u16 ADC_vidReturnResult(void)
{
	/*ADC Start Conversion in Single Conversion Mode*/
	SetBit(ADCSRA,ADSC);
	while(GetBit(ADCSRA,ADIF)==0);
	SetBit(ADCSRA,ADIF);

	return ADCRegister;
}
/*
*ADC Interrupt Flag
*GetBit(ADCSRA,ADIF)
*/

