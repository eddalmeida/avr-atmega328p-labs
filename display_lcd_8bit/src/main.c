/*==================================================================
Autor: Edson Almeida
Data: 22/04/2026
Projeto: Capítulo 5 – Trabalho com display LCD na interface 8bit (I/O)

Descrição:
Implementação de rotinas utilizando o microcontrolador ATmega328P,
com foco na manipulação de portas digitais e na
geração de efeitos visuais com display lcd.

Referência:
LIMA, Charles Borges; Marco V. M. VILLAÇA.
"AVR e Arduino: Técnica de Projetos".
====================================================================*/

#define F_CPU 16000000UL                         //Frequencia CPU 16Mhz
#include <avr/io.h>                              //Para trabalho com Registradores AVR
#include <util/delay.h>                          //Para uso de delays     
#include <stdint.h>                              //Para declarar int 8 bit
#include <avr/pgmspace.h>                        //Para Armazenar constantes na flash
#include "../headers/macros.h"


//=============================MAPEAMENTO DE HARDWARE==================================
#define DADOS_LCD PORTD    //Port de controle do LCD 
#define CONTR_LCD PORTB    //Barramento de dados do LCD
#define RS PB1             //Pino de instrucao ou caracteres, 0 instrucao e 1 caracteres
#define E PB0              //Pino de enable do display
//=====================================================================================

//============================PROTOTIPOS DE FUNCOES====================================
void cmd_LCD(uint8_t c, uint8_t cd);             //C byte,  e CD instrucao ou caractere
void init_lcd();                                 //Rotina para iniciar conforme Datasheet
void printf_lcd(const char *c);                  //Print de string
//=====================================================================================

const unsigned char msg1[] PROGMEM = "Ola display!";

int main()
{
    CONTR_LCD = 0xFF;                                                //configura PORTB como saida
    DADOS_LCD = 0xFF;                                                //Configura PORTD como saida
    CONTR_LCD = 0x00;                                                //Inicia PORTB como 0
    DADOS_LCD = 0x00;                                                //Inicia PORTD como 0

    init_lcd();

    for(uint8_t i = 0; i < 12; i++)
    {
        cmd_LCD(pgm_read_byte(&msg1[i]), 1);                         //envia caractere por caractere
    }

    while (1)
    {
        for(uint8_t i = 0; i < 12; i++)
        {
            cmd_LCD(pgm_read_byte(&msg1[i]), 1);                      //envia caractere por caractere
        }

        _delay_ms(1000);

        cmd_LCD(0x01, 0);
        printf_lcd("Func printf");

        _delay_ms(1000);
        cmd_LCD(0x01, 0);
    }//end while(true)
    
    
}//end main


void cmd_LCD(uint8_t c, uint8_t cd)
{
    DADOS_LCD = c;

    if (cd == 0)                                                     //Se instrucao coloca pino RS como 0
    {
        clr_bit(CONTR_LCD, RS);
    }
    else
    {
        set_bit(CONTR_LCD, RS);
    }

    pulse_enable();

    if((cd == 0) && (c < 4))                                        //Se instrucao de limpeza ou retorno de cursor, aguardar o tempo necessario
    {
        _delay_ms(2);
    }
    
}//end cmd_LCD

void init_lcd()                                                    //rotina de init para modo 8bit seguindo o datasheet do fabricante
{
    clr_bit(CONTR_LCD, RS);                                        //RS sempre zero durante iniciacao
    _delay_ms(20);

    cmd_LCD(0x38, 0);                                              //Instrucao para configurar display modo 8 bit, enviar 3 vezes para garantir que dislay recebeu e informacao
     _delay_ms(2);

    cmd_LCD(0x38, 0);
    _delay_us(200);

    cmd_LCD(0x38, 0);                                              

    cmd_LCD(0x0E, 0);                                             //Ativa display e liga o cursor 
    _delay_ms(2);

    cmd_LCD(0x01, 0);                                             //Limpa o display
    _delay_ms(2);

    cmd_LCD(0x06, 0);                                             //Configura entry mode para deslocar para direita apos escrita
}//end init_lcd

void printf_lcd(const char *c)
{
    for (; *c != '\0'; c++)                                        
    {
        cmd_LCD(*c, 1);
    }
}//end printf_lcd