#ifndef MACROS_H

#define read(PINx, Px) ((PINx & (1 << Px)) >> Px)                  //macro para ler botao e retornar 1 ou 0
#define set_bit(PORTx, Px) (PORTx |= (1 << Px))                    //macro para colocar pino como alto
#define clr_bit(PORTx, Px) (PORTx &= ~(1 << Px))                   //macro para colocar pino como baixo
#define toggle_bit(PORTx, Px) (PORTx ^= (1 << Px))                 //macro para trocar estado de um pino

#define pulse_enable() _delay_ms(1); set_bit(CONTR_LCD, E); _delay_ms(1); clr_bit(CONTR_LCD, E); _delay_ms(1);  //macro para dar um pulso no enable





#define MACROS_H
#endif