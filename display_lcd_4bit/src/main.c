/*==================================================================
Autor: Edson Almeida
Data: 22/04/2026
Projeto: Capítulo 5 – Trabalho com display LCD na interface 4bit (I/O)

Descrição:
Implementação de rotinas utilizando o microcontrolador ATmega328P,
com foco na manipulação de portas digitais e na
geração de efeitos visuais com display lcd.

Referência:
LIMA, Charles Borges; Marco V. M. VILLAÇA.
"AVR e Arduino: Técnica de Projetos".
====================================================================*/



#define F_CPU 16000000UL
#include "../headers/macros.h"
#include "../headers/display.h"




int main()
{
    DDRB = 0xFF;
    DDRD = 0xFF;
    CONTR_LCD = 0x00;
    DADOS_LCD = 0x00;

    init_lcd();

    for(int8_t i = 0; i < 16; i++)
    {
        cmd_LCD('*', 1);
            
    }

    while(1)
    {
        for(int8_t i = 0; i < 16; i++)
        {
            cmd_LCD((0x80 + i), 0);
            _delay_ms(30);
        }

        for(int8_t i = 0; i < 16; i++)
        {
            cmd_LCD((0x8F - i), 0);
            _delay_ms(30);
        }
        

    }
}

