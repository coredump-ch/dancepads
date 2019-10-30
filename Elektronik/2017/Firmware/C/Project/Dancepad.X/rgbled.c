/* 
 * File:   rgbled.c
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#include <xc.h>

void init_rgbled()
{
    //Set TRIS bits of RGB outputs
    TRISCbits.RC1 = 1;
    TRISCbits.RC2 = 1;
    TRISBbits.RB5 = 1;
    
    //Select timer resources, Timer2 all PWM and load with PWM period value
    CCPTMRS0 = 0x00;
    PR2 = 0xff;
    
    //Set up PWM mode for RC1
    CCP1CON = 0b00001100; 
    CCPR1L = 0x00;

    //Set up PWM mode for RC2
    CCP2CON = 0b00001100;
    CCPR2L = 0x00;
    
    //Set up PWM mode for RB5
    CCP3CON = 0b00001100;
    CCPR3L = 0x00;
    
    //Set Timer 2 On, 1:1 Post, 4x prescale
    T2CON = 0b00000101;   
    
    //Clear TRIS bits of RGB outputs
    TRISCbits.RC1 = 0; 
    TRISCbits.RC2 = 0;
    TRISBbits.RB5 = 0;
}

void set_rgbled(int r, int g, int b)
{
    //Set red LED PWM
    int brightness = r;
    CCP2CONbits.DC2B0 = (unsigned int) brightness & 1; 
    CCP2CONbits.DC2B1 = (unsigned int) (brightness >> 1) & 1; 
    CCPR2L = (unsigned int) (brightness >> 2);
    
    //Set green LED PWM
    brightness = g;
    CCP3CONbits.DC3B0 = (unsigned int) brightness & 1;
    CCP3CONbits.DC3B1 = (unsigned int) (brightness >> 1) & 1; 
    CCPR3L = (unsigned int) (brightness >> 2);      
    
    //Set blue LED PWM
    brightness = b;
    CCP1CONbits.DC1B0 = (unsigned int) brightness & 1; 
    CCP1CONbits.DC1B1 = (unsigned int) (brightness >> 1) & 1; 
    CCPR1L = (unsigned int) (brightness >> 2); 
}
