#define _XTAL_FREQ  64000000
#include <P18F23K22.h>
#include <xc.h>
#include "init.h"
#include "rgbled.h"

long a = 0;
int b = 0;

void init_rgbled()
{
    PORTBbits.RB5 = 0;
    LATBbits.LB5 = 0;
    TRISBbits.RB5 = 0;
  
    PORTCbits.RC1 = 0;
    LATCbits.LC1 = 0;
    TRISCbits.RC1 = 0;
  
    PORTCbits.RC2 = 0;
    LATCbits.LC2 = 0;
    TRISCbits.RC2 = 0;
}

void blink_rgbled()
{
    a++;
    if (a == 500000)
    {
        PORTCbits.RC2 = ~PORTCbits.RC2;
        a = 0;
    }
    
    if (a == 100000)
    {
        PORTCbits.RC1 = ~PORTCbits.RC1;
    }
    
    if (a == 200000)
    {
        PORTBbits.RB5 = ~PORTBbits.RB5;
    }
}
