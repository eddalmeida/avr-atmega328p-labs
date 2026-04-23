#ifndef DISPLAY_H
#define DISPLAY_H
#include <stdint.h>


//=============================MAPEAMENTO DE HARDWARE==================================
#define DADOS_LCD PORTD    //Port de controle do LCD 
#define CONTR_LCD PORTB    //Barramento de dados do LCD
#define RS PB1             //Pino de instrucao ou caracteres, 0 instrucao e 1 caracteres
#define E PB0              //Pino de enable do display
#define nibble_dados 1     // 1 para dados nos dados MSB do port e 0 para os dados no LSB do port
#define pulse_enable _delay_ms(1); set_bit(CONTR_LCD, E); _delay_ms(1); clr_bit(CONTR_LCD, E); _delay_ms(1);
//=====================================================================================


//============================PROTOTIPOS DE FUNCOES====================================
void cmd_LCD(uint8_t c, uint8_t cd);             //C byte,  e CD instrucao ou caractere
void init_lcd();                                 //Rotina para iniciar conforme Datasheet
void printf_lcd(const char *c);                  //Print de string
//=====================================================================================


#endif