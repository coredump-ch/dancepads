#define _XTAL_FREQ  64000000
#include <p18f23k22.h>
#include <xc.h>
#include "init.h"
#include "rgbled.h"

long a = 0;
int b = 0;

void init_rgbled()
{
    // Set TRIS bits of RGB outputs
    TRISCbits.RC1 = 1;
    TRISCbits.RC2 = 1;
    TRISBbits.RB5 = 1;
    
    // Select timer resources, Timer2 all PWM and load with PWM period value
    CCPTMRS0 = 0x00;
    PR2 = 0xff;
    
    // Set up PWM mode for RC1
    CCP1CON = 0b00001100; 
    CCPR1L = 0x00;

    // Set up PWM mode for RC2
    CCP2CON = 0b00001100;
    CCPR2L = 0x00;
    
    // Set up PWM mode for RB5
    CCP3CON = 0b00001100;
    CCPR3L = 0x00;
    
    // Set Timer 2 On, 1:1 Post, 4x prescale
    T2CON = 0b00000101;   
    
    // Clear TRIS bits of RGB outputs
    TRISCbits.RC1 = 0; 
    TRISCbits.RC2 = 0;
    TRISBbits.RB5 = 0;
}

void set_rgbled(int r, int g, int b)
{
    int brightness = r;
    
    CCP2CONbits.DC2B0 = brightness & 1; //set low bit 
    CCP2CONbits.DC2B1 = (brightness >> 1) & 1;  //set second lowest 
    CCPR2L = (brightness >> 2); //set highest eight 
    
    int brightness = g;
    
    CCP3CONbits.DC3B0 = brightness & 1; //set low bit 
    CCP3CONbits.DC3B1 = (brightness >> 1) & 1;  //set second lowest 
    CCPR3L = (brightness >> 2); //set highest eight      
    
    int brightness = b;
        
    CCP1CONbits.DC1B0 = brightness & 1; //set low bit 
    CCP1CONbits.DC1B1 = (brightness >> 1) & 1;  //set second lowest 
    CCPR1L = (brightness >> 2); //set highest eight 
}
