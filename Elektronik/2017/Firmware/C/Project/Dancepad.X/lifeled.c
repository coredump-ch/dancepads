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
        mul = get_i2c_data();
        if (j >= mul*freq)
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
