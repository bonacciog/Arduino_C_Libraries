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

	//	Output: CLK -> pin 12 (PB4), DIN -> pin 10 (PB2), CS -> pin 11 (PB3)

void main()
{
		//	CLK -> OUTPUT, DIO -> OUTPUT, CS -> OUTPUT
	port_setup_set_data_direction_output_bits_port_B(0b00011100);							
	
		//	CLK -> LOW, DIO -> LOW, CS -> LOW
	port_set_low_bits_port_B(0b11100011);												
	
		//	Setto impostazioni di default
	led_matrix_8x8_set_default_setting();													

		// 	Scrivo i dati (accendo led)

	while(1)
	{
		led_matrix_8x8_write_data_output(0b00000001, 0b00111100);
		led_matrix_8x8_write_data_output(0b00000010, 0b01000010);
		led_matrix_8x8_write_data_output(0b00000011, 0b10101001);
		led_matrix_8x8_write_data_output(0b00000100, 0b10000101);
		led_matrix_8x8_write_data_output(0b00000101, 0b10000101);
		led_matrix_8x8_write_data_output(0b00000110, 0b10101001);
		led_matrix_8x8_write_data_output(0b00000111, 0b01000010);
		led_matrix_8x8_write_data_output(0b00001000, 0b00111100);
		_delay_ms(2000);
		led_matrix_8x8_write_data_output(0b00000001, 0b00111100);
		led_matrix_8x8_write_data_output(0b00000010, 0b01000010);
		led_matrix_8x8_write_data_output(0b00000011, 0b10100101);
		led_matrix_8x8_write_data_output(0b00000100, 0b10001001);
		led_matrix_8x8_write_data_output(0b00000101, 0b10001001);
		led_matrix_8x8_write_data_output(0b00000110, 0b10100101);
		led_matrix_8x8_write_data_output(0b00000111, 0b01000010);
		led_matrix_8x8_write_data_output(0b00001000, 0b00111100);
		_delay_ms(2000);
	}

}

