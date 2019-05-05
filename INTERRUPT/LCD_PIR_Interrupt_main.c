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
#include "Interrupt_lib.h"

	//	OUTPUT: D0-D7 collegati alla PORTA D, RS a PIN 9 (PORTA B BIT 1), E a PIN 8 (PORTA B BIT 0) 
	//	INPUT:  PIN 12 (PCINT 4 bit 4 PORTA B)


int main(void)
{
		//	PIR INTERRUPT
	interrupt_disable();
	    //  setup del pin 12 come input 
  	port_setup_set_data_direction_input_bits_port_B(0b11101111);
        //  Abilito pull-down                                
  	port_set_high_bits_port_B(0b11101111);                                                    
        //  Abilito il Bit relativo a PCINT4 nella maschera PCMSK0
  	interrupt_msk_setup_set_interrupt_0_7_bits_pcmsk_0(0b00010000);  
        //  Abilito la maschera 0 nel registro PCICR                                            
  	interrupt_pcicr_setup_set_interrupt_bits_pcie(0b00000001);
  
        //  setup interrupt
  	interrupt_enable();

  		//	SETUP LCD
  		// PORTD -> OUTPUT
	port_set_all_bits_data_direction_port_D(0b11111111);
		// RS -> OUTPUT
	port_setup_set_data_direction_output_bits_port_B(0b00000010);
		// E -> OUTPUT
	port_setup_set_data_direction_output_bits_port_B(0b00000001);

		// SETTO IMPOSTAZIONI DI DEFAULT SUL DISPLAY
	lcd_display_set_default_setting();

	BYTE frase[] = { 'I', 'N', ' ', 'A', 'T', 'T', 'E', 'S', 'A', '.', '.', '.' };

	while(1)
	{
		lcd_display_set_command(LCD_DISPLAY_CLEAR_DATA_COMMAND);
		lcd_display_set_command(LCD_DISPLAY_CHOSE_FIRST_ROW_COMMAND);
		int index;
		for(index=0; index<sizeof(frase); index++)
			lcd_display_write_character(frase[index]);
		_delay_ms(1000);
	}
}

        //  la funzione interrupt handler non ha un valore di ritorno perchè la funzione sorgente (ISR, vedi commands.h) è stata definita senza valore di ritorno in avr/interrupt.h
interrupt_handler(PCINT0_vect)
{
        //	Segnala sullo schermo che è arrivato un interrupt
	lcd_display_set_command(LCD_DISPLAY_CLEAR_DATA_COMMAND);
		//	Scelgo la riga da cui iniziare a scrivere
	lcd_display_set_command(LCD_DISPLAY_CHOSE_FIRST_ROW_COMMAND);
	BYTE frase[] = { 'E', ' ', 'A', 'R', 'R', 'I', 'V', 'A', 'T', 'O', ' ', 'U','N',' ', 'I', 'N', 'T', 'E', 'R', 'R', 'U', 'P', 'T', '!', };
	int index;
	for(index=0; index<sizeof(frase); index++)
	{
			//	Colonne prima riga terminate, inizio a scrivere sula seconda
		if(index==16)
			lcd_display_set_command(LCD_DISPLAY_CHOSE_SECOND_ROW_COMMAND);
		lcd_display_write_character(frase[index]);
	}
	_delay_ms(2000);
		//	Ripulisco e scelgo di nuovo la prima riga
	lcd_display_set_command(LCD_DISPLAY_CLEAR_DATA_COMMAND);
	lcd_display_set_command(LCD_DISPLAY_CHOSE_FIRST_ROW_COMMAND);

}
