/*
 * LCD.c
 *
 * Created: 7/28/2018 11:08:40 PM
 * Author : karim fathy
 */ 

#include <avr/io.h>
#include "lcd.h"
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void)
{
	LCD_init(); /* initialize LCD */
	LCD_displayString("Eng Hossam Adel");
	_delay_ms(4000); /* wait four seconds */
    LCD_displayStringRowColumn(1,5,"ooohh");

	
	
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

