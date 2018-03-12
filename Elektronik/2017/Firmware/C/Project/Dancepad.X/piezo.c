#define _XTAL_FREQ  64000000
#include <p18f23k22.h>
#include <xc.h>
#include "init.h"
#include "piezo.h"

void init_piezo()
{
//    ADCON2 = 0xAF;
    
    ADCON2 = 0xA7; // Set to internal clock and 8 TAD
    ADCON1 = 0x00; // Set reference voltage to supply voltage
    
    TRISAbits.RA0 = 0;
    ANSELAbits.ANSA0 = 0;
    
    TRISAbits.RA1 = 0;
    ANSELAbits.ANSA1 = 0;
    
    TRISAbits.RA2 = 0;
    ANSELAbits.ANSA2 = 0;
    
    TRISAbits.RA3 = 0;
    ANSELAbits.ANSA3 = 0;
}

unsigned int adc_convert(unsigned char ch)
{
    if(ch>4) return 0;  //Invalid Channel
    
    ADCON0=0x00;
    ADCON0=(ch<<2);   //Select ADC Channel
   
    ADCON0bits.ADON = 1;   //Set ADC on
    ADCON0bits.GODONE =1;  //Start conversion
    while(ADCON0bits.GODONE); //wait for the conversion to finish
    ADCON0bits.ADON = 0; // Set ADC off

    if(ADRES<7) return 0;
    
    return ADRES;
}

unsigned int read_piezo()
{
    unsigned int piezo0, piezo1, piezo2, piezo3;
    static unsigned int piezo_tot = 0;
    
    piezo0 = adc_convert(0);
    piezo1 = adc_convert(1);
    piezo2 = adc_convert(2);
    piezo3 = adc_convert(3);
    
    piezo_tot = piezo_tot + piezo0 - piezo1 + piezo2 - piezo3;
    if (piezo_tot > 1536)
    {
        piezo_tot = 0;
    }
    return piezo_tot;
}