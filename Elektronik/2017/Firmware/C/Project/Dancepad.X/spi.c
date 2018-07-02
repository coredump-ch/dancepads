/* 
 * File:   spi.c
 * Author: astoc
 *
 * Created on 19. March 2018, 23:06
 */

#include <xc.h>
#include "spi.h"

void init_spimaster()
{
    SSP2STAT &= 0x3F;
    SSP2CON1 = 0x00;
    
    //Set TRIS bits of SPI master
    TRISBbits.TRISB0 = 0;      //!SS2
    TRISBbits.TRISB1 = 0;      //SCK2
    TRISBbits.TRISB2 = 1;      //SDI2
    TRISBbits.TRISB3 = 0;      //SDO2
    
    ANSELBbits.ANSB0 = 0;
    ANSELBbits.ANSB1 = 0;
    ANSELBbits.ANSB2 = 0;
    ANSELBbits.ANSB3 = 0;
    
    //Disable Chipselect
    PORTBbits.RB0 = 1;
    
    //Set up SPI
    SSP2STAT |= 0x40;
    SSP2CON1 |= 0x20;
}

void init_spislave()
{
    SSP1STAT &= 0x3F;
    SSP1CON1 = 0x04;
    
    //Set TRIS bits of SPI slave
    TRISAbits.TRISA5 = 1;      //!SS1
    TRISCbits.TRISC3 = 1;      //SCK1
    TRISCbits.TRISC4 = 1;      //SDI1
    TRISCbits.TRISC5 = 0;      //SDO1
        
    ANSELAbits.ANSA5 = 0;
    ANSELCbits.ANSC3 = 0;
    ANSELCbits.ANSC4 = 0;
    ANSELCbits.ANSC5 = 0;

    //Set up SPI
    SSP1STAT |= 0x40;
    SSP1CON1 |= 0x20;
}

unsigned char send_spimaster(unsigned char data)
{
    unsigned char TempVar;
    
    //Read dummy values
    TempVar = SSP2BUF;
    
    //Reset Interruption flag
    PIR3bits.SSP2IF = 0;
    
    //Enable Chipselect
    PORTBbits.RB0 = 0;   
 
    //Start Data transmission
    SSP2BUF = data;

    //Wait for Data Transmit/Receipt complete
    while(!PIR3bits.SSP2IF);

    //Enable Chipselect
    PORTBbits.RB0 = 1;
    
    //Return reseived value
    return(SSP2BUF);

}

unsigned char rec_spislave(unsigned char data)
{
    unsigned int i = 0;

    //Reset Interruption flag
    PIR1bits.SSP1IF = 0;
    
    //Send Dummy transmission for reading the data
    SSP1BUF = data;
    
    //Wait for Data Transmit/Receipt complete
    while(!PIR1bits.SSP1IF && i < 1000)
    {
        i++;
    }
    
    //Return reseived value
    return(SSP1BUF);
}
