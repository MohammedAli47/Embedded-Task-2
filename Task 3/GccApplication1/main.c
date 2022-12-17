#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "stdTypes.h"

int main(void)
{
	u8 arrOfNumbers[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
	u8 numberDisplayed = 50;
    DDRA = 0xfc;
	PORTA = 0x00;
	DDRC = 0xfe;
	PORTC = 0x00;
	DDRD = 0x03;
	PORTD = 0x00;
    while (1) {
		u8 rightSeg = numberDisplayed % 10, leftSeg = (numberDisplayed / 10) % 10;
		u8 sw1_pressed = (PINA >> 0) & 1;
		u8 sw2_pressed = (PINA >> 1) & 1;
		if (sw1_pressed && (numberDisplayed < 99)) // Only Switch 1 is Pressed
		{
			_delay_ms(40);
			numberDisplayed++;
		} else if (sw2_pressed && (numberDisplayed > 0)) // Only Switch 2 is Pressed
		{
			_delay_ms(40);
			numberDisplayed--;
		} else
		{
			PORTD |=  (1<<0);				// Enable right segment
			PORTD &= ~(1<<1);				// Disable left segment
			PORTC = arrOfNumbers[rightSeg];	// Display on right segment
			_delay_ms(2);
			PORTD &= ~(1<<0);				// Disable right segment
			PORTD |=  (1<<1);				// Enable left segment
			PORTC = arrOfNumbers[leftSeg];	// Display on left segment
			_delay_ms(2);
		}
	}
}
