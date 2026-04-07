#include <avr/io.h>
#include "avr/pgmspace.h"                                          //Biblioteca para escrever na flash
#include <util/delay.h>                                            //Biblioteca para utilizar delay
#include <stdint.h>


#define read(PINx, Px) ((PINx & (1 << Px)) >> Px)                 //macro para ler bot�o e retornar 1 ou 0
#define set_bit(PORTx, Px) (PORTx |= (1 << Px))                    //macro para colocar pino como alto
#define clr_bit(PORTx, Px) (PORTx &= !(1 << Px))                   //macro para colocar pino como baixo

#define btn1 PB2                                                   //define bot�o1 no PB0
#define btn2 PB3                                                   //define bot�o2 no PB0
#define DISPLAY PORTD                                              //define display no PORTD



const unsigned int numero[] PROGMEM = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71}; // Tabela para display

uint8_t estadoant1 = 1;                                              //amarzena estado anterior do bot�o1 para ler apenas 1 vez
uint8_t estadoant2 = 1;                                              //amarzena estado anterior do bot�o2 para ler apenas 1 vez


void display_print(int valor);                                       //declara��o da fun��o para pintar no display


int main(void)
{
	DDRB = 0b11110011;                                               //configura PORTB como saida
    DDRD = 0xFF;                                                     //configura PORTD como saida
	PORTB = 0b00001100;                                              //Inicia PORTB como 0 e ativa pull-up PB2 e PB3
	PORTD = 0x00;                                                    //Inicia PORTD como 0
	UCSR0B = 0x00;                                                   //Condigura PD0 e PD1 como I/O
	
	uint8_t contador = 0;                                       //variavel contador
	
    while (1) 
    {
		
		uint8_t botao1 = read(PINB, btn1);                          //armazena valor do botao1 
		uint8_t botao2 = read(PINB, btn2);                          //amarzena estado anterior do bot�o para ler apenas 1 vez
		
		
		if (botao1 == 0 && estadoant1 == 1)                           //leitura bot�o de decrementar
		{
			contador++;
			_delay_ms(10);
			                            
		}
		
		   
		if (botao2 == 0 && estadoant2 == 1)                           //leitura de bot�o de decrementar 
		{ 
			contador--;
			_delay_ms(10);
			                              
		}
		
		if(contador > 99) contador = 0;                               //contador = 0 se for negativo ou > 99
		
		
		estadoant2 = botao2;                                          //amarzena estado anterior do bot�o1
		estadoant1 = botao1;                                          //amarzena estado anterior do bot�o1
		
		
		display_print(contador);
    }
}

void display_print(int valor)                                         //fun��o multiplexa��o display 7 segmentos
{
	int digito1 = valor / 10;                                         // separa o numero mais significativo
	int digito2 = valor - (digito1 * 10);                             // separa o numero menos significativo
	
	DISPLAY = 0x00;                                                   // limpa display antes de colocar valor
	clr_bit(PORTB, PB1);                                         
	set_bit(PORTB, PB0);                                              // seleciona para escrever no display da direita
	DISPLAY =  pgm_read_byte(&numero[digito2]);
	
	_delay_ms(5);
	
	DISPLAY = 0x00;
	clr_bit(PORTB, PB0);
	set_bit(PORTB, PB1);                                              // seleciona para escrever no display da esquerda 
	DISPLAY =  pgm_read_byte(&numero[digito1]);
	
	_delay_ms(5);
			
}
