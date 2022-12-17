#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "stdTypes.h"
int main(void)
{
	u8 arrOfNumbers[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
	u8 numberDisplayed = 0;
    DDRA = 0xfc;
	PORTA = 0x00;
	DDRC = 0xff;
	PORTC = 0x00;
    while (1) {
		u8 sw1_pressed = (PINA >> 0) & 1;
		u8 sw2_pressed = (PINA >> 1) & 1;
		if (sw1_pressed && (numberDisplayed < 9))
		{
			_delay_ms(40);
			numberDisplayed++;
		} else if (sw2_pressed && (numberDisplayed > 0))
		{
			_delay_ms(40);
			numberDisplayed--;
		} else
		{
			PORTC = arrOfNumbers[numberDisplayed];
		}
	}
}
