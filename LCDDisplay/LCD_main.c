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

int main(void)
{
		//	PORTD -> OUTPUT
	port_set_all_bits_data_direction_port_D(0b11111111);
		//	RS -> OUTPUT
	port_setup_set_data_direction_output_bits_port_B(0b00000010);
		//	E -> OUTPUT
	port_setup_set_data_direction_output_bits_port_B(0b00000001);

		//	SETTO IMPOSTAZIONI DI DEFAULT SUL DISPLAY
	lcd_display_set_default_setting();

		//	SCRIVO SU DISPLAY
	BYTE frase[] = { 'H', 'E', 'L', 'L', '0', ' ', 'W', 'O', 'R', 'L', 'D', '!' };
	int index;
	for(index=0; index<sizeof(frase); index++)
		lcd_display_write_character(frase[index]);
	while(1);

}
