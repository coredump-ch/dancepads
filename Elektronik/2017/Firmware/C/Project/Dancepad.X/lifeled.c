/* 
 * File:   lifeled.c
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#include <xc.h>
#include "spimaster.h"

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

void blink_spiled()
{
    static unsigned int i, j, a = 0, rec_spiled;
    //Blink LED after each second
    i++;
    if (i >= 100)
    {
        if (a == 1)
        {
            send_spimaster(85);
            a = 2;
        }
        else
        {
            send_spimaster(170);
            a = 1;
        }
        i = 0;
    }
    
    rec_spiled = 0;
    rec_spiled = rec_spislave();
    
    if (rec_spiled == 85)
    {
        PORTAbits.RA4 = 1;
    }
    else
    {
        if (rec_spiled == 170)
        {
            PORTAbits.RA4 = 0;
        }
        else
        {
            if (rec_spiled == 0)
            {
                j++;
                if (j >= 500)
                {
                    PORTAbits.RA4 = (unsigned int) ~PORTAbits.RA4;
                    j = 0;
                }
            }
        }
    }
}
