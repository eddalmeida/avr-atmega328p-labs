/*==================================================================
Autor: Edson Almeida
Data: 12/04/2026
Projeto: Capítulo 5 – Portas de Entrada e Saída (I/O)

Descrição:
Implementação de rotinas utilizando o microcontrolador ATmega328P,
com foco na manipulação de portas digitais (PORTD) e na
geração de efeitos visuais com LEDs.

Referência:
LIMA, Charles Borges; VILLAÇA, Marco V. M.
"AVR e Arduino: Técnica de Projetos".
====================================================================*/



#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "../headers/macros.h"

void vaiEvolta();
void vaiEvolta_unico_led();
void vaiEvolta_apagando();
void contagemBinaria_crescente();
void contagemBinaria_decrescente();



int main()
{
    DDRD = 0xFF;
    PORTD = 0x00;

    while(1)
    {
        vaiEvolta();
        vaiEvolta_unico_led();
        vaiEvolta_apagando();
        contagemBinaria_crescente();
        contagemBinaria_decrescente();
    }
}

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
            _delay_ms(100);           
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