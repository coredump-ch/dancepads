/* 
 * File:   lifeled.c
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#include <xc.h>

void init_lifeled()
{
    //Set LED as a digital output
    PORTAbits.RA4 = 0;
    LATAbits.LA4 = 0;
    TRISAbits.RA4 = 0;
}

void blink_lifeled()
{
    static int i;
    //Blink LED after each second
    i++;
    if (i == 1000)
    {
        PORTAbits.RA4 = (unsigned int) ~PORTAbits.RA4;
        i = 0;
    }
}
