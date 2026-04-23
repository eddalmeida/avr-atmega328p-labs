#include "../headers/display.h"
#include "../headers/macros.h"

void cmd_LCD(uint8_t c, uint8_t cd)
{
    if(cd == 0)
    {
        clr_bit(CONTR_LCD, RS);
    }
    else
    {
        set_bit(CONTR_LCD, RS);
    }

    #if (nibble_dados)
    DADOS_LCD = (DADOS_LCD & 0x0F) | (0x0F | c);
    #else
    DADOS_LCD = (DADOS_LCD & 0xF0) | (0x0F | (c >> 4));
    #endif

    
}
