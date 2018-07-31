

#include "lcd.h"

check_error LCD_init(void)
{
	check_error state= STATE_SUCCESS;
	LCD_DATA_PORT_DIR = 0xFF; 
	LCD_CTRL_PORT_DIR |= (1<<E) | (1<<RS) | (1<<RW); 
	
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE); 
	
	LCD_sendCommand(CURSOR_OFF);
	
	LCD_sendCommand(CLEAR_COMMAND); 
	return state;
}

check_error LCD_sendCommand(enum_command command)
{
	check_error state = STATE_SUCCESS;
	if((command> init_comm)&&(command<last_comm))
	{
		CLEAR_BIT(LCD_CTRL_PORT,RS); 
		CLEAR_BIT(LCD_CTRL_PORT,RW); 
		_delay_ms(1); 
		SET_BIT(LCD_CTRL_PORT,E); 
		_delay_ms(1); 
		LCD_DATA_PORT = command; 
		_delay_ms(1); 
		CLEAR_BIT(LCD_CTRL_PORT,E);
		_delay_ms(1); 
    }
	else state =STATE_INAVALIED_COMMAND;

	return state;
}

check_error LCD_displayCharacter(ukimo8 data)
{
	check_error state= STATE_SUCCESS;
	
		SET_BIT(LCD_CTRL_PORT,RS); 
		CLEAR_BIT(LCD_CTRL_PORT,RW); 
		_delay_ms(1);
		SET_BIT(LCD_CTRL_PORT,E);
		_delay_ms(1); 
		LCD_DATA_PORT = data; 
		_delay_ms(1); 
		CLEAR_BIT(LCD_CTRL_PORT,E); 
		_delay_ms(1); 	
	
return state;
}

check_error LCD_displayString(const ukimo8 *Str)
{
	ukimo8 i = 0;
	check_error state= STATE_SUCCESS;
	if(Str!= NULL)
	{
		while(Str[i] != '\0')
		{
			LCD_displayCharacter(Str[i]);
			i++;
		}
	}
	else state=STATE_INVALIED_STRING;
	return state;
}
	

check_error LCD_goToRowColumn(ukimo8 row,ukimo8 col)
{
	check_error state= STATE_SUCCESS;
	ukimo8 Address=0;
	
	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		
	}					
	LCD_sendCommand(Address | SET_CURSOR_LOCATION);
	return state; 
}

check_error LCD_displayStringRowColumn(ukimo8 row,ukimo8 col,const ukimo8 *Str)
{
	check_error state= STATE_SUCCESS;
	LCD_goToRowColumn(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
	return state;
}



check_error LCD_clearScreen(void)
{
	check_error state=STATE_SUCCESS;
	LCD_sendCommand(CLEAR_COMMAND); 
	return state;
}
