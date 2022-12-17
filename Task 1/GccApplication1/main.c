#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "stdTypes.h"
int main(void)
{
    DDRA = 0x03;
	PORTA = 0x00;
	DDRB = 0xf8;
	PORTB = 0x00;
    while (1) {
		u8 sw1_pressed = (PINB >> 0) & 1;
		u8 sw2_pressed = (PINB >> 1) & 1;
		u8 sw3_pressed = (PINB >> 2) & 1;
		if (sw1_pressed && !sw2_pressed && !sw3_pressed) // Only Switch 1 is Pressed
		{
			PORTA |=  (1<<0);
			PORTA &= ~(1<<1);
		} else if (!sw1_pressed && sw2_pressed && !sw3_pressed) // Only Switch 2 is Pressed
		{
			PORTA &= ~(1<<0);
			PORTA |=  (1<<1);
		} else if (!sw1_pressed && !sw2_pressed && sw3_pressed) // Only Switch 3 is Pressed
		{
			PORTA |=  (1<<0);
			PORTA |=  (1<<1);
		} else // No Switch is Pressed
		{
			PORTA &= ~(1<<0);
			PORTA &= ~(1<<1);
		}
	}
}
