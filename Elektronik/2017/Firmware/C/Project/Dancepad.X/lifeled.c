#define _XTAL_FREQ  64000000
#include <P18F23K22.h>
#include <xc.h>
#include "init.h"
#include "lifeled.h"

long i = 0;

void init_lifeled()
{
    PORTA = 0x00;
    LATA = 0x00;
    TRISA = 0x00;
}

void blink_lifeled()
{
    i++;
    if (i == 500000)
    {
        PORTAbits.RA4 = ~PORTAbits.RA4;
        i = 0;
    }
}
