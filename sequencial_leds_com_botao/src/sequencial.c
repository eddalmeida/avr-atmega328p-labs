#include <avr/io.h>
#include <util/delay.h>
#include "../headers/sequencial.h"

void vaiEvolta()
{
    for(uint8_t i = 0; i < 8; i++)
        {
            PORTD |= (1 << i);
            _delay_ms(100);           
        }

        PORTD = 0x00;
        _delay_ms(60);

        for(int8_t i = 7; i >= 0; i--)
        {
            PORTD |= (1 << i);
            _delay_ms(60);           
        }

        PORTD = 0x00; 
        _delay_ms(100);
}

void vaiEvolta_unico_led()
{
    for(uint8_t i = 0; i < 8; i++)
        {
            PORTD = (1 << i);
            _delay_ms(35);           
        }

        PORTD = 0x00;
        _delay_ms(100);

        for(int8_t i = 7; i >= 0; i--)
        {
            PORTD = (1 << i);
            _delay_ms(35);           
        }

        PORTD = 0x00; 
        _delay_ms(100);
}

void vaiEvolta_apagando()
{
        for(uint8_t i = 0; i < 8; i++)
        {
            PORTD |= (1 << i);
            _delay_ms(100);           
        }

        _delay_ms(100);

        for(int8_t i = 7; i >= 0; i--)
        {
            PORTD &= ~(1 << i);
            _delay_ms(25);           
        }

        _delay_ms(100);
}

void contagemBinaria_crescente()
{
    for(uint8_t i = 0; i < 255; i++)
    {
        PORTD = i;
        _delay_ms(10);
    }
}
void contagemBinaria_decrescente()
{
    for(int16_t i = 255; i >= 0; i--)
    {
        PORTD = i;
        _delay_ms(10);
    }
}

void strobe()
{   
    PORTD = 0x00;
    for(uint8_t i = 0; i < 6; i++)
    {
        PORTD ^= 0xFF;
       _delay_ms(75);
    }

    _delay_ms(200);
}