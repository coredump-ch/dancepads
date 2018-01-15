#define _XTAL_FREQ  64000000
#include <p18f23k22.h>
#include <xc.h>
#include "init.h"
#include "lifeled.h"

long i = 0;

void init_lifeled()
{
    PORTAbits.RA4 = 0;
    LATAbits.LA4 = 0;
    TRISAbits.RA4 = 0;
}

void blink_lifeled()
{
    i++;
    if (i == 1000)
    {
        PORTAbits.RA4 = ~PORTAbits.RA4;
        i = 0;
    }
}
