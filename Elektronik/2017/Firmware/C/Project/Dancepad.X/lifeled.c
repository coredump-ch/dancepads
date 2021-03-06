/* 
 * File:   lifeled.c
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#include <xc.h>
#include "spi.h"
#include "i2c.h"
#include "dancepad.h"

void init_lifeled()
{
    //Set LED as a digital output
    PORTAbits.RA4 = 0;
    LATAbits.LA4 = 0;
    TRISAbits.RA4 = 0;

}

void blink_lifeled(unsigned char dir)
{
    static int i;
    static int j;
    
    //Blink LED after each second
    i++;
    if (i == 20000)
    {
        i = 0;
        j++;
        if ((j <= 2 && dir == dir_right) || (j <= 4 && dir == dir_straight) || (j <= 6 && dir == dir_left) || (j <= 8 && dir == dir_master) || (j <= 10 && dir == dir_error))
        {
            PORTAbits.RA4 = (unsigned int) ~PORTAbits.RA4;
        }
        if (j >= 10)
        {
            j = 0;
        }
    }
}
/*
//Blink life LED interrupt
void high_priority interrupt interrupt_lifeled()
{
    
}
*/
void blink_spiled(unsigned char dir, unsigned int freq)
{
    static unsigned int i, j, a = 0, mul = 0, rec_spiled;
    //Blink LED after each second
    i++;
    if (i >= 1000)
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
    
    //Falls nicht der Master oder Fehler
    if (dir == dir_right || dir == dir_straight || dir == dir_left)
    {
        rec_spiled = 0;
        rec_spiled = rec_spislave(0);

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
    /*            if (rec_spiled == 0)
                {
                    j++;
                    if (j >= 500)
                    {
                        PORTAbits.RA4 = (unsigned int) ~PORTAbits.RA4;
                        j = 0;
                    }
                }*/
            }
        }
    }
    
    //Wenn es der Master ist
    if (dir == dir_master)
    {
        j++;
        if (j >= freq)
        {
            PORTAbits.RA4 = (unsigned int) ~PORTAbits.RA4;
            j = 0;
        }
/*      if (mul == 2)
        {
            PORTAbits.RA4 = (unsigned int) ~PORTAbits.RA4;
        }*/
    }
}


void set_lifeLed(unsigned char led)
{
    PORTAbits.RA4 = led;
}