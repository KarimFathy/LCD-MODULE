

#ifndef LCD_H_
#define LCD_H_

#include "types.h"
#include "common_macros.h"
#include "conf.h"

/* LCD HW Pins */
#define RS PD4
#define RW PD5
#define E  PD6
#define LCD_CTRL_PORT PORTD
#define LCD_CTRL_PORT_DIR DDRD
#define LCD_DATA_PORT PORTC
#define LCD_DATA_PORT_DIR DDRC

/* LCD Commands */
typedef enum {
	init_comm=0x00,
 CLEAR_COMMAND= 0x01,
TWO_LINE_LCD_Eight_BIT_MODE= 0x38,
 CURSOR_OFF= 0x0C,
 CURSOR_ON= 0x0E,
 SET_CURSOR_LOCATION= 0x80,
 last_comm=0xff,
}enum_command;

check_error LCD_init(void);
check_error LCD_sendCommand(enum_command command);
check_error LCD_displayCharacter(ukimo8 data);
check_error LCD_displayString(const ukimo8 *Str);
check_error LCD_clearScreen(void);
check_error LCD_displayStringRowColumn(ukimo8 row,ukimo8 col,const ukimo8 *Str);
check_error LCD_goToRowColumn(ukimo8 row,ukimo8 col);




#endif