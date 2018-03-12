/* 
 * File:   init.c
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#include <p18f23k22.h>

void init_oscillator()
{
    //SCS FOSC; IRCF 16MHz_HFINTOSC; IDLEN disabled; 
    OSCCON = 0x70;
    
    //PRISD enabled; SOSCGO disabled; MFIOSEL disabled;
    OSCCON2 = 0x04;
    
    //INTSRC disabled; PLLEN enabled; TUN 0; 
    OSCTUNE = 0x40;
    
    //Wait for PLL to stabilize
    while(PLLRDY == 0)
    {
    }    
}
