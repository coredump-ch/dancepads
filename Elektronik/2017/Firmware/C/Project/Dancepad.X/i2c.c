/* 
 * File:   i2c.c (USB interface)
 * Author: astoc
 *
 * Created on 19. April 2018, 17:29
 */

#include <xc.h>
#include "i2c.h"

// Global variable
static unsigned char i2c_receive_data;
static unsigned char i2c_transmit_data;
static unsigned char address;

void init_i2cslave()
{
    //Set TRIS bits of I2C (USB) slave
    TRISCbits.TRISC3 = 1;       //SCL1
    TRISCbits.TRISC4 = 1;       //SDA1
    
    ANSELCbits.ANSC3 = 0;
    ANSELCbits.ANSC4 = 0;
    
    SSPADD = 0x14;              // Adress is 0A
    SSP1CON1 = 0x36;            // I2C mode, 7 bit Address length
    SSP1STAT = 0x00;            // Reset status register
    SSP1CON2 = 0x00;            // Start I2C
    
    PIR1bits.SSP1IF = 0;
    PIE1bits.SSP1IE = 1;
    
    PIR2bits.BCL1IF = 0;
    PIE2bits.BCL1IE = 1;
    
    INTCONbits.GIE_GIEH  = 1;   // GIE/GIEH: Global Interrupt Enable bit
    INTCONbits.PEIE_GIEL = 1;   // PEIE/GIEL: Peripheral Interrupt Enable bit
    
    SSP1CON3bits.SCIE=1;        //Start Condition Interrupt Enable bit
    SSP1CON3bits.PCIE=1;        //Stop Condition Interrupt Enable bit
}


void __interrupt () rec_i2c(unsigned char data)
{
    if(PIR1bits.SSPIF)
    {
        PIR1bits.SSPIF  = 0;
        if (SSP1STATbits.BF) 
        {
            address = SSP1BUF;
            if (!SSP1STATbits.R_NOT_W)      // Read Data from I2C (USB)
            {
                while (SSP1STATbits.S)
                {
                    if(PIR1bits.SSPIF)
                    {
                        PIR1bits.SSPIF  = 0;
                        if (SSP1STATbits.BF) 
                        {
                            i2c_receive_data = SSP1BUF;
                        }
                    }
                }
            }
            else if (SSP1STATbits.R_NOT_W)      // Write Data from I2C (USB)
            {
                while (SSP1STATbits.S)
                {
                    if (!SSP1CON2bits.ACKSTAT)
                    {
                        SSP1BUF = i2c_transmit_data;
                        i2c_transmit_data = 0;
                        
                        SSP1CON1bits.CKP = 1;
                        while(!PIR1bits.SSPIF)
                        {
                        }
                        PIR1bits.SSPIF  = 0;
                    }
                }
            }
        }
    }
}
        
 
unsigned char get_i2c_data()
{    
    return(i2c_receive_data);
}

int send_i2c_data(unsigned char data)
{
    if (i2c_transmit_data == 0)
    {
        i2c_transmit_data = data;
    }
    else
    {
        return(-1);
    }
}
