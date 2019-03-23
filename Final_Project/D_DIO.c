/*
 * DIO.c
 *
 *  Created on: Jan 12, 2019
 *      Author: Hanoon-PC
 */
#include "TYPES.h"
#include "MACROS.h"
#include "D_DIO.h"

extern void DIO_vidSetPinDirection(u8 port,u8 pin,u8 dir)
{
	switch (port)
	{
	case (PORT_A):
			if (dir==1)
			{
				SetBit(DDRA,pin);
			}
			else if(dir==0)
			{
				ClrBit(DDRA,pin);
			}
	break;

	case (PORT_B):
			if (dir==1)
			{
				SetBit(DDRB,pin);
			}
			else if(dir==0)
			{
				ClrBit(DDRB,pin);
			}
	break;

	case (PORT_C):
			if (dir==1)
			{
				SetBit(DDRC,pin);
			}
			else if(dir==0)
			{
				ClrBit(DDRC,pin);
			}
	break;

	case (PORT_D):
			if (dir==1)
			{
				SetBit(DDRD,pin);
			}
			else if(dir==0)
			{
				ClrBit(DDRD,pin);
			}
	break;

	}
}

extern void DIO_vidWritePinValue(u8 port,u8 pin,u8 value)
{
	switch (port)
	{
	case (PORT_A):
			if (value==1)
			{
				SetBit(PORTA,pin);
			}
			else if(value==0)
			{
				ClrBit(PORTA,pin);
			}
	break;

	case (PORT_B):
			if (value==1)
			{
				SetBit(PORTB,pin);
			}
			else if(value==0)
			{
				ClrBit(PORTB,pin);
			}
	break;

	case (PORT_C):
			if (value==1)
			{
				SetBit(PORTC,pin);
			}
			else if(value==0)
			{
				ClrBit(PORTC,pin);
			}
	break;

	case (PORT_D):
			if (value==1)
			{
				SetBit(PORTD,pin);
			}
			else if(value==0)
			{
				ClrBit(PORTD,pin);
			}
	break;

	}
}

extern u8 DIO_u8GetPinValue(u8 port,u8 pin)
{
	switch (port)
	{
	case (PORT_A):

	return GetBit(PINA,pin);

	break;

	case (PORT_B):

	return GetBit(PINB,pin);

	break;

	case (PORT_C):

	return GetBit(PINC,pin);

	break;

	case (PORT_D):

	return GetBit(PIND,pin);

	break;

	default: return 0;

	}

}

extern void DIO_vidSetPortDirection(u8 port, u8 Dir)
{
	switch (port)
	{
	case(PORT_A):
			DDRA=Dir;
	break;
	case(PORT_B):
			DDRB=Dir;
	break;
	case(PORT_C):
			DDRC=Dir;
	break;
	case(PORT_D):
			DDRD=Dir;
	break;

	}
}

extern void DIO_vidWritePortValue(u8 port, u8 value)
{
	switch (port)
	{
	case(PORT_A):
			PORTA=value;
	break;
	case(PORT_B):
			PORTB=value;
	break;
	case(PORT_C):
			PORTC=value;
	break;
	case(PORT_D):
			PORTD=value;
	break;

	}
}
