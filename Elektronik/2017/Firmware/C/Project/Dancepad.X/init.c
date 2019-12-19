/* 
 * File:   init.c
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#define _XTAL_FREQ  64000000
#include <xc.h>
#include "dancepad.h"

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


unsigned char init_direction()
{
    //Send Chipselect signal
    TRISBbits.TRISB0 = 0;
    ANSELBbits.ANSB0 = 0;
    PORTBbits.RB0 = 1;
    
    //Set inputs to recognize direction of dancepad connection
    TRISCbits.TRISC6 = 1;   //Right
    TRISCbits.TRISC7 = 1;   //Left
    TRISBbits.TRISB4 = 1;   //Straight
        
    ANSELCbits.ANSC6 = 0;
    ANSELCbits.ANSC7 = 0;
    ANSELBbits.ANSB4 = 0;
    
    //Wait small time for initialization
    __delay_ms(3000);
    
    //Check if dancepad is master = 100
    if (!PORTBbits.RB4 && !PORTCbits.RC6 && !PORTCbits.RC7)
    {
        return(dir_master);
    }
    
    //Check if dancepad is right = 140
    if (!PORTBbits.RB4 && PORTCbits.RC6 && !PORTCbits.RC7)
    {
        return(dir_right);    // Add this line.
//       return(dir_master);      // Remove this line.
    }
    
    //Check if dancepad is staight = 160
    if (PORTBbits.RB4 && !PORTCbits.RC6 && !PORTCbits.RC7)
    {
        return(dir_straight); // Add this line.
//       return(dir_master);      // Remove this line.
    }
    
    //Check if dancepad is left = 180
    if (!PORTBbits.RB4 && !PORTCbits.RC6 && PORTCbits.RC7)
    {
        return(dir_left);     // Add this line.
//       return(dir_master);      // Remove this line.
    }
    
    return(dir_error);
}