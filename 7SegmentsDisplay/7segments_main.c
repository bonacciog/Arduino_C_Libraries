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
#include "7segments.h"

		//	Output: CLK a pin 12 (PB4) e DIO a pin 11 (PB3)

int main()
{
		//	DIO -> OUTPUT
	    //	CLK -> OUTPUT
	port_setup_set_data_direction_output_bits_port_B(0b00011000);
		//	CLK -> LOW
	port_set_low_bits_port_B(0b11101111);
		//	DIO -> LOW
	port_set_low_bits_port_B(0b11110111);

		//	Accendo i segmenti
	BYTE initial_segments[] = { 0b00111111, 0b10111111, 0b00111111, 0b00111111 };
	display_7segments_set_segments(initial_segments, 4, 0);
	_delay_ms(3000);
	while(1)
	{
		BYTE done[] = { 0b11011110, 0b00111111, 0b01010100, 0b01111001 };
		display_7segments_set_segments(done, 4, 0);
	}
}
