/*
*					 Tesi di laurea
*			  			   in
*				Calcolatori Elettronici T
*
*	Sviluppo di progetti per fini didattici con Arduino
*
*
*					GIOVANNI BONACCIO
*/

	//	Suppongo D0-D7 collegati alla PORTA D, RS a PIN 9 (PORTA B BIT 1), E a PIN 8 (PORTA B BIT 0) 

#ifndef _LCD_H_
#define _LCD_H_

#include "common_commands.h"

#define LCD_DISPLAY_CHOSE_FIRST_ROW_COMMAND    					0b10000000
#define LCD_DISPLAY_CHOSE_SECOND_ROW_COMMAND    				0b11000000
#define LCD_DISPLAY_CLEAR_DATA_COMMAND    						0b00000001
#define LCD_DISPLAY_TURN_ON_COMMAND_WITH_CURSOR   				0b00001110
#define	LCD_DISPLAY_TURN_ON_COMMAND_WITHOUT_CURSOR				0b00001100 
#define	LCD_DISPLAY_INIZIALIZE_7x5_MATRIX_COMMAND				0b00111000
/*
*	Setta impostazioni di default:
*	LCD_DISPLAY_INIZIALIZE_7x5_MATRIX_COMMAND
*	LCD_DISPLAY_TURN_ON_COMMAND_WITHOUT_CURSOR
*	LCD_DISPLAY_CLEAR_DATA_COMMAND
*	LCD_DISPLAY_CHOSE_FIRST_COLUMN_COMMAND
*	Permette di evitare l'utilizzo 
*	della lcd_display_set_command()
*/
void lcd_display_set_default_setting();

/*	
*	Permette di impostare sul display
*	un comando (impostazione) passato 
*	come parametro
*/
void lcd_display_set_command(BYTE code);

/*	
*	Permette di scrivere sul display
*	un carattere passato come parametro
*	seguendo le impostazioni settate 
*	con la lcd_display_set_command().
*/
void lcd_display_write_character(BYTE character);

#endif