#define _XTAL_FREQ  64000000
#include <P18F23K22.h>
#include <xc.h>
#include "init.h"
#include "rgbled.h"

long a = 0;
int b = 0;

void init_rgbled()
{
    PORTB = 0x00;
    LATB = 0x00;
    TRISB = 0x00;
    
    PORTC = 0x00;
    LATC = 0x00;
    TRISC = 0x00;
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
        PORTBbits.RB5 = ~PORTBbits.RB5;
    }
    
    if (a == 200000)
    {
        PORTBbits.RB5 = ~PORTBbits.RB5;
    }
}
