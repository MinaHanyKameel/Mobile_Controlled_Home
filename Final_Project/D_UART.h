/*
 * UART.h
 *
 *  Created on: Feb 23, 2019
 *      Author: Hanoon-PC
 */

#ifndef D_UART_H_
#define D_UART_H_

//USART I/O Data Register – UDR
#define UDR *((u8 *)0x2C)

//USART Control and Status Register A – UCSRA
#define UCSRA *((u8 *)0x2B)

#define MPCM PIN0
#define U2X PIN1
#define PE PIN2
#define DOR PIN3
#define FE PIN4
#define UDRE PIN5
#define TXC PIN6
#define RXC PIN7

#define UCSRB *((u8 *)0x2A)

#define TXB8 PIN0
#define RXB8 PIN1
#define UCSZ2 PIN2
#define TXEN PIN3
#define RXEN PIN4
#define UDRIE PIN5
#define TXCIE PIN6
#define RXCIE PIN7

#define UCSRC *((u8 *)0x40)

#define UCPOL PIN0
#define UCSZ0 PIN1
#define UCSZ1 PIN2
#define USBS PIN3
#define UPM0 PIN4
#define UPM1 PIN5
#define UMSEL PIN6
#define URSEL PIN7

//USART Baud Rate Registers – UBRRL and UBRRH
#define UBRRL *((u8 *)0x29)

#define UBRRH *((u8 *)0x40)
#define URSEL PIN7

u8 UART_vidReceive(void);
void UART_vidSend(u8 DATA);
void UART_vidInit(void);

#endif /* D_UART_H_ */
