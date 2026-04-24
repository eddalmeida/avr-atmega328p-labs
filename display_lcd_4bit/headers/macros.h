#ifndef MACROS_H

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define read(PINx, Px) ((PINx & (1 << Px)) >> Px)                  //macro para ler botao e retornar 1 ou 0
#define set_bit(PORTx, Px) (PORTx |= (1 << Px))                    //macro para colocar pino como alto
#define clr_bit(PORTx, Px) (PORTx &= ~(1 << Px))                   //macro para colocar pino como baixo
#define toggle_bit(PORTx, Px) (PORTx ^= (1 << Px))                 //macro para inverter bit 

#define MACROS_H
#endif