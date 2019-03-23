#include "TYPES.h"
#include "H_EEPROM.h"

#include "util/delay.h"
#include "H_Bluetooth_UART.h"
void eeprom_init(void)
{
	i2c_init_master();
}

void eeprom_write_byte(unsigned short address, unsigned char data)
{
    i2c_start();
	i2c_send_slave_address_with_write_req( 0x50 | ((address & 0x0700)>>8) );
	i2c_write_byte((unsigned char)address);
	i2c_write_byte(data);
	i2c_stop();
    return;
}

unsigned char eeprom_read_byte(unsigned short address)
{
	unsigned char data;
	i2c_start();
	i2c_send_slave_address_with_write_req( 0x50 | ((address & 0x0700)>>8) );
    i2c_write_byte((unsigned char)address);
	i2c_repeated_start();
	i2c_send_slave_address_with_read_req( 0x50 | ((address & 0x0700)>>8) );
	data = i2c_read_byte();
	i2c_stop();
    return data;
}

void EEPROM_vidEEPROM_WriteString(u16 Address, u8* Data)
{
	u8 i=0;
	while(Data[i]!='\0')
	{
		eeprom_write_byte(Address+i,Data[i]);
		i++;
		_delay_ms(5);
	}
	return;
}
