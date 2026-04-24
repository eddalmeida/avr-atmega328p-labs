#include "../headers/display.h"
#include "../headers/macros.h"
void cmd_LCD(uint8_t c, uint8_t cd)
{
    if(cd == 0)
        clr_bit(CONTR_LCD, RS);
    else
        set_bit(CONTR_LCD, RS);

    #if (nibble_dados)

    // nibble alto (MSB)
    DADOS_LCD = (DADOS_LCD & 0x0F) | (c & 0xF0);
    pulse_enable();

    // nibble baixo
    DADOS_LCD = (DADOS_LCD & 0x0F) | ((c << 4) & 0xF0); 
    pulse_enable();

    #else

    // nibble alto (LSB mode)
    DADOS_LCD = (DADOS_LCD & 0xF0) | ((c >> 4) & 0x0F);
    pulse_enable();

    // nibble baixo
    DADOS_LCD = (DADOS_LCD & 0xF0) | (c & 0x0F);
    pulse_enable();

    #endif

    if(c < 4)
        _delay_ms(5);
}

void init_lcd()
{
    clr_bit(CONTR_LCD, RS);
    clr_bit(CONTR_LCD, E);

    _delay_ms(20);

    #if(nibble_dados)

    // 0x30 (3x) -> ainda em modo 8 bits
    DADOS_LCD = (DADOS_LCD & 0x0F) | 0x30;
    pulse_enable();
    _delay_ms(5);

    DADOS_LCD = (DADOS_LCD & 0x0F) | 0x30;
    pulse_enable();
    _delay_us(200);

    DADOS_LCD = (DADOS_LCD & 0x0F) | 0x30;
    pulse_enable();
    _delay_us(200);

    // entra em modo 4 bits (0x20)
    DADOS_LCD = (DADOS_LCD & 0x0F) | 0x20;
    pulse_enable();
    _delay_us(200);

    #else

    DADOS_LCD = (DADOS_LCD & 0xF0) | 0x03;
    pulse_enable();
    _delay_ms(5);

    DADOS_LCD = (DADOS_LCD & 0xF0) | 0x03;
    pulse_enable();
    _delay_us(200);

    DADOS_LCD = (DADOS_LCD & 0xF0) | 0x03;
    pulse_enable();
    _delay_us(200);

    DADOS_LCD = (DADOS_LCD & 0xF0) | 0x02;
    pulse_enable();
    _delay_us(200);

    #endif

    cmd_LCD(0x28, 0); // 4 bits, 2 linhas, 5x8
    cmd_LCD(0x08, 0); // display OFF
    cmd_LCD(0x01, 0); // clear
    _delay_ms(2);
    cmd_LCD(0x06, 0); // entry mode
    cmd_LCD(0x0E, 0); // display ON
    cmd_LCD(0x80, 0); // DDRAM = 0
}


void printf_lcd(const char *c)                                           //Funcao para enviar string para o display
{
    for (; *c != '\0'; c++)                                        
    {
        cmd_LCD(*c, 1);
    }

}

