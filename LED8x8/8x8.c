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
#include "8x8.h"

	// CLK -> pin 12 (PB4), DIN -> pin 10 (PB2), CS -> pin 11 (PB3)

static void led_matrix_8x8_write_byte(BYTE data);

void led_matrix_8x8_write_data_output(BYTE address, BYTE data)
{
		//	CS -> LOW
	port_set_low_bits_port_B(0b11110111);
		//	Passo l'indirizzo su cui scrivere i dati												
	led_matrix_8x8_write_byte(address);
		//	Scrivo i dati
	led_matrix_8x8_write_byte(data);
		//	CS -> HIGH
	port_set_high_bits_port_B(0b00001000);											
}

void led_matrix_8x8_set_default_setting()
{
		//	decode (always no decode)
	led_matrix_8x8_write_data_output(0b00001001, 0b00000000);
		//	Brightness -> 2 (0..15)
    led_matrix_8x8_write_data_output(0b00001010, 0b00000010); 
    	//	Display digits (always 7, digit = column)
    led_matrix_8x8_write_data_output(0b00001011, 0b00000111);  
    	//  Shutdown (0x01 Normal | 0x00 Shutdown)    						
    led_matrix_8x8_write_data_output(0b00001100, 0b00000001);
    	//	Display test (0x01 Test | 0x00 Normal)       						
    led_matrix_8x8_write_data_output(0b00001111, 0b00000000); 
}

void led_matrix_8x8_write_byte(BYTE data)
{
	int counter_bit;
		//	Invio un bit alla volta
	for(counter_bit=0; counter_bit < 8; counter_bit++)
	{
			//	CLK -> LOW
		port_set_low_bits_port_B(0b11101111);

			// Discrimino se mandare 0 o 1
		if((data & 0b10000000) == 0)
			port_set_low_bits_port_B(0b11111011);
		else
		    port_set_high_bits_port_B(0b00000100);
			// Shifto al prossimo bit
        data = data << 1;
        	//	CLK -> HIGH
		port_set_high_bits_port_B(0b00010000);			
	}	
}
