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
    
        //  Output: Bit 0 della porta B (pin 8) [LED ROSSO] - Bit 7 della porta D (pin 7) [LED GIALLO] - Bit 4 della porta B (pin 12) [LED VERDE] 

        //  setup del bit 0 e bit 4 della porta b, bit 7 della porta D come OUTPUT
    port_setup_set_data_direction_output_bits_port_B(0b00010001);                           
    port_setup_set_data_direction_output_bits_port_D(0b10000000);                           
    while(1)
    {
            //  alternanza led
        port_set_high_bits_port_B(0b00000001);                                             
        _delay_ms(5000);
        port_set_low_bits_port_B(0b11111110);
        port_set_high_bits_port_B(0b00010000);                                                     
        _delay_ms(5000);
        port_set_low_bits_port_B(0b11101111);                                             
        port_set_high_bits_port_D(0b10000000);                                             
        _delay_ms(2000);
        port_set_low_bits_port_D(0b01111111);                                             
    }

}
