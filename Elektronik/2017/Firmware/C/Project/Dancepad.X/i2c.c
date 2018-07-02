/* 
 * File:   22c.c
 * Author: astoc
 *
 * Created on 19. April 2018, 17:29
 */

#include <xc.h>
#include "i2c.h"

void init_i2cslave()
{
    //Set TRIS bits of I2C slave
    TRISCbits.TRISC3 = 1;      //SCL1
    TRISCbits.TRISC4 = 1;      //SDA1
    
//    LATCbits.LC3 = 1;
//    LATCbits.LC4 = 1;
    
    ANSELCbits.ANSC3 = 0;
    ANSELCbits.ANSC4 = 0;
    
    SSPADD = 0x08;                 // Adress is 0A
    SSP1CON1 = 0x36;                // I2C mode, 7 bit Address length
    SSP1STAT = 0x00;                // Reset status register
    SSP1CON2 = 0x01;                // Start I2C
    
    PIR1bits.SSP1IF = 0;
    PIE1bits.SSP1IE = 1;
    
    PIR2bits.BCL1IF = 0;
    PIE2bits.BCL1IE = 1;
    
    INTCONbits.GIE_GIEH  = 1;       // GIE/GIEH: Global Interrupt Enable bit
    INTCONbits.PEIE_GIEL = 1;       // PEIE/GIEL: Peripheral Interrupt Enable bit

//    PIR1bits.SSP1IF = 0;
    
    SSP1CON3bits.SCIE=1; //Start Condition Interrupt Enable bit
    SSP1CON3bits.PCIE=1; //Stop Condition Interrupt Enable bit
}

//#pragma interruptlow rec_i2c
unsigned char interrupt rec_i2c(unsigned char data)
//unsigned char rec_i2c(unsigned char data)
{
    unsigned char read_data;
    
    PORTAbits.RA4 = 1;
/*    if (PIR1bits.SSP1IF) {
        
        if (!SSP1STATbits.D_NOT_A) {
            //
            // Slave Address 
            //
            //i2c_byte_count = 0;

            if (SSP1STATbits.BF) {
                // Discard slave address 
                read_data = SSP1BUF;    // Clear BF
            }
            
            if (SSP1STATbits.R_NOT_W) {                
                // Reading - read from register map
                SSP1CON1bits.WCOL = 0;
                SSP1BUF           = data;
            } 
            
        } else {
            //
            // Data bytes 
            //
            //i2c_byte_count++;

            if (SSP1STATbits.BF) {
                read_data = SSP1BUF;    // Clear BF
            }

            if (SSP1STATbits.R_NOT_W) {

                // Multi-byte read - advance to next address
                SSP1CON1bits.WCOL = 0;
                SSP1BUF           = data;
                //LATDbits.LATD6 = 1;
                
            } else {                

                /*if (i2c_byte_count == 1) {
                    // First write byte is register address
                    i2c_reg_addr = sspBuf;

                } else {
                    // Write to register address - auto advance
                    //   to allow multiple bytes to be written
                    i2c_reg_map[i2c_reg_addr++] = sspBuf;
                }*/
 /*           }
        }
        // Limit address to size of register map
        //i2c_reg_addr %= sizeof(i2c_reg_map);
        
        // Finally
        PIR1bits.SSPIF  = 0;            // Clear MSSP interrupt flag
        SSP1CON1bits.CKP = 1;            // Release clock 
        return(read_data);
    }    */
}

