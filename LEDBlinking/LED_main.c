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
		//  Output: Bit 0 della porta b (pin 8)

        //  setup del pin 8 come output
    port_setup_set_data_direction_output_bits_port_B(0b00000001);


    while(1)
    {	  //  alterno lo stato del bit 0 della porta b : accendo e spengo led
        port_set_high_bits_port_B(0b00000001);																						 
        _delay_ms(1000);
        port_set_low_bits_port_B(0b00000000); 											
        _delay_ms(1000);
    }

}	