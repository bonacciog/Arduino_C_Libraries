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
#include "LCD.h"

	//	Suppongo D0-D7 collegati alla PORTA D, RS a PIN 9 (PORTA B BIT 1), E a PIN 8 (PORTA B BIT 0) 

static void lcd_display_command_enable();

static void lcd_display_data_enable();

void lcd_display_set_default_setting()
{
	lcd_display_set_command(LCD_DISPLAY_INIZIALIZE_7x5_MATRIX_COMMAND);
	lcd_display_set_command(LCD_DISPLAY_TURN_ON_COMMAND_WITHOUT_CURSOR);
	lcd_display_set_command(LCD_DISPLAY_CLEAR_DATA_COMMAND);
	lcd_display_set_command(LCD_DISPLAY_CHOSE_FIRST_ROW_COMMAND);	
}

void lcd_display_set_command(BYTE code)
{
		//	Setto i bit della porta D secondo il comando passato come parametro
	port_set_all_bits_port_D(code);
		//	Abilito il comando settato
	lcd_display_command_enable();
}

void lcd_display_write_character(BYTE character)
{
		//	Scrivo il carattere nella porta D
	port_set_all_bits_port_D(character);
		//	Abilito la visualizzazione dei dati settati
	lcd_display_data_enable();
}

void lcd_display_command_enable()
{
		//	RS -> LOW (Devo settare della impostazioni perciò non serve che il registro salvi i dati)
	port_set_low_bits_port_B(0b11111101);
		//	E -> HIGH (Preparo fronte di discesa)
	port_set_high_bits_port_B(0b00000001);
	_delay_ms(50);
		//	E -> LOW (Fronte di discesa)
	port_set_low_bits_port_B(0b11111110);
}

void lcd_display_data_enable()
{
		//	RS -> high (Seleziono il registro perchè sto per mandare i dati)
	port_set_high_bits_port_B(0b00000010);
		//	E -> HIGH (Preparo fronte di discesa)
	port_set_high_bits_port_B(0b00000001);
	_delay_ms(50);
		//	E -> LOW (Fronte di discesa)
	port_set_low_bits_port_B(0b11111110);
}