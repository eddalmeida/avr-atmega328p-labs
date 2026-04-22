/*==================================================================
Autor: Edson Almeida
Data: 12/04/2026
Projeto: Capítulo 5 – Trabalho com display LCD na interface 8bit (I/O)

Descrição:
Implementação de rotinas utilizando o microcontrolador ATmega328P,
com foco na manipulação de portas digitais (PORTD) e na
geração de efeitos visuais com display lcd.

Referência:
LIMA, Charles Borges; VILLAÇA, Marco V. M.
"AVR e Arduino: Técnica de Projetos".
====================================================================*/



#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "../headers/macros.h"


int main()
{
    DDRD = 0xFF;
    PORTD = 0x00;

    while(1)
    {

    }
}