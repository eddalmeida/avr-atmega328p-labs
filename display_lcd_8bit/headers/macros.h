#ifndef MACROS_H

#define read(PINx, Px) ((PINx & (1 << Px)) >> Px)                  //macro para ler botao e retornar 1 ou 0
#define set_bit(PORTx, Px) (PORTx |= (1 << Px))                    //macro para colocar pino como alto
#define clr_bit(PORTx, Px) (PORTx &= ~(1 << Px))                   //macro para colocar pino como baixo


#define MACROS_H
#endif