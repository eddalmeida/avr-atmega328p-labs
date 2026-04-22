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
#include "../headers/sequencial.h"




int main()
{
    DDRB = 0x00;
    DDRD = 0xFF;

    PORTD = 0x00;
    PORTB = 0x03;

    uint8_t contador = 1;
    uint8_t antbtn2 = 1;
    
    while(1)
    {
        uint8_t btn1 = read(PINB, PB0);
        uint8_t btn2 = read(PINB, PB1);

        if(btn1 == 0)
        {
            _delay_ms(10);
            if (read(PINB, PB0) == 0)
            {
                if (btn2 == 0 && antbtn2 == 1)
                {
                    contador++;
                    if(contador > 7)contador = 1;
                }
                
            }    
            
            PORTD = contador;
        }

        if(btn1 == 1){
            switch (contador)
            {
                case 1:
                    vaiEvolta();
                    break;
    
                case 2:
                    vaiEvolta_unico_led();
                    break; 
                
                case 3:
                    vaiEvolta_apagando();
                    break;
    
                case 4:
                    contagemBinaria_crescente();
                    break; 

                case 5:
                    contagemBinaria_decrescente();
                    break;
    
                case 6:
                    strobe();
                    break; 
                case 7:
                    vaiEvolta_unico_led();
                    strobe();
                    break; 
            }
        }

        antbtn2 = btn2;
    }
}

