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

static void display_7segments_start_writing();

static void display_7segments_stop_writing();

static void display_7segments_write_byte(BYTE data);


void display_7segments_set_segment(BYTE segment, BYTE position)
{
		//	ESEGUO FRONTI PER CLK E DIO PER INIZIARE LA SCRITTURA
	display_7segments_start_writing();
		//	ESEGUO COMANDO 1 CONTROLLER
	display_7segments_write_byte(CONTROLLER_IO_COMMAND1);
		//	ESEGUO FRONTI PER CLK E DIO PER TERMINARE LA SCRITTURA
	display_7segments_stop_writing();


		//	ESEGUO FRONTI E RIPETO PASSAGGIO PER COMANDO 2 DEL CONTROLLER E INIZIO SCRITTURA DATI
	display_7segments_start_writing();
	display_7segments_write_byte(CONTROLLER_IO_COMMAND2 | position);
	
	display_7segments_write_byte(segment);
	display_7segments_stop_writing();

		//	ESEGUO COMANDO 3 CONTROLLER E IMPOSTO LUMINOSITA DI DEFAULT
	display_7segments_start_writing();
	display_7segments_write_byte(CONTROLLER_IO_COMMAND3 | default_brightness | CONTROLLER_SET_DISPLAY_ON);
	display_7segments_stop_writing();


}

void display_7segments_set_segments(BYTE segments[], BYTE lenght, BYTE starter_position)
{
		//	ESEGUO FRONTI PER CLK E DIO PER INIZIARE LA SCRITTURA
	display_7segments_start_writing();
		//	ESEGUO COMANDO 1 CONTROLLER
	display_7segments_write_byte(CONTROLLER_IO_COMMAND1);
		//	ESEGUO FRONTI PER CLK E DIO PER TERMINARE LA SCRITTURA
	display_7segments_stop_writing();


		//	ESEGUO FRONTI E RIPETO PASSAGGIO PER COMANDO 2 DEL CONTROLLER E INIZIO SCRITTURA DATI
	display_7segments_start_writing();
	display_7segments_write_byte(CONTROLLER_IO_COMMAND2 | starter_position);
	int index = 0;
	for(index=0; index<lenght; index++)
		display_7segments_write_byte(segments[index]);
	display_7segments_stop_writing();

		//	ESEGUO COMANDO 3 CONTROLLER E IMPOSTO LUMINOSITA DI DEFAULT
	display_7segments_start_writing();
	display_7segments_write_byte(CONTROLLER_IO_COMMAND3 | default_brightness | CONTROLLER_SET_DISPLAY_ON);
	display_7segments_stop_writing();


}

void display_7segments_start_writing()
{
		//	CLK -> HIGH
	port_set_high_bits_port_B(0b00010000);
		//	DIO -> HIGH
	port_set_high_bits_port_B(0b00001000);
		//	DIO -> LOW
	port_set_low_bits_port_B(0b11110111);

}

void display_7segments_stop_writing()
{
		//	CLK -> LOW
	port_set_low_bits_port_B(0b11101111);
		//	DIO -> LOW
	port_set_low_bits_port_B(0b11110111);
		//	CLK -> HIGH
	port_set_high_bits_port_B(0b00010000);

		//	DIO -> HIGH
	port_set_high_bits_port_B(0b00001000);
}

void display_7segments_write_byte(BYTE data)
{
	int bit; BYTE ack;
	for(bit=0; bit<8; bit++)
	{
			//	CLK -> LOW
		port_set_low_bits_port_B(0b11101111);

			// Discrimino se mandare 0 o 1
		if(data & 0b00000001)
		{
				//	DIO -> HIGH
			port_set_high_bits_port_B(0b00001000);
		}
		else
		{
	    		//	DIO -> LOW
			port_set_low_bits_port_B(0b11110111);
		}


	    	//	CLK -> HIGH
		port_set_high_bits_port_B(0b00010000);

			//	Shifto al prossimo bit
		data = data >> 1;
	}
		//	CLK -> LOW
	port_set_low_bits_port_B(0b11101111);
		//	DIO -> INPUT
	port_setup_set_data_direction_input_bits_port_B(0b11110111);
		//	DIO -> HIGH
	port_set_high_bits_port_B(0b00001000);
	ack = (((PINB & 0b00001000) > 0) ? 1 : 0); 
	if(ack)
	{		//	DIO -> OUTPUT
		port_setup_set_data_direction_output_bits_port_B(0b00001000);
			//	DIO -> LOW
		port_set_low_bits_port_B(0b11110111);
	}

		//	CLK -> HIGH
	port_set_high_bits_port_B(0b00010000);
		//	CLK -> LOW
	port_set_low_bits_port_B(0b11101111);
		//	DIO -> OUTPUT
	port_setup_set_data_direction_output_bits_port_B(0b00001000);

}