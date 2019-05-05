/*
*                    Tesi di laurea
*                          in
*               Calcolatori Elettronici T
*
*   Sviluppo di progetti per fini didattici con Arduino
*
*
*                   GIOVANNI BONACCIO
*/
#include "lampeggioLED.h"

void main(void)
{
		//  Output: Bit 0-7 della porta D (pin 0-7)

        //  setup dei pin 0-7 come output
    port_setup_set_data_direction_output_bits_port_D(0b11111111);


    while(1)
    {	  //  accendo/spengo i led [QUESTO COMPONENTE UTILIZZA UNA LOGICA NEGATIVA]
        port_set_high_bits_port_D(0b11111111);
        port_set_low_bits_port_D(0b01111110);																						 
        _delay_ms(1000);
        port_set_high_bits_port_D(0b11111111);
        port_set_low_bits_port_D(0b10111101); 											
        _delay_ms(1000);
        port_set_high_bits_port_D(0b11111111);
        port_set_low_bits_port_D(0b11011011);                                          
        _delay_ms(1000);
        port_set_high_bits_port_D(0b11111111);
        port_set_low_bits_port_D(0b11100111);                                          
        _delay_ms(1000);
    }

}	
