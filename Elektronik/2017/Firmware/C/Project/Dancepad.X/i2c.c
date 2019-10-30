/* 
 * File:   i2c.c
 * Author: astoc
 *
 * Created on 19. April 2018, 17:29
 */

#include <xc.h>
#include "i2c.h"

// Global variable
static unsigned char i2c_read_data;

void init_i2cslave()
{
    //Set TRIS bits of I2C slave
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
    if (!SSP1STATbits.R_NOT_W) {    // Daten empfangen
        while (!SSP1STATbits.P)
        {
            if (PIR1bits.SSP1IF) {
                PIR1bits.SSPIF  = 0;
                if (SSP1STATbits.BF) {
                    i2c_read_data = SSP1BUF;
                }
            }
        }
    }
}
        
 
unsigned char get_i2c_data()
{
    return(i2c_read_data);
    i2c_read_data = 0;
}
