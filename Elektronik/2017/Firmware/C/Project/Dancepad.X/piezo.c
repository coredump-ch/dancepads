/* 
 * File:   piezo.c
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#include <xc.h>

void init_piezo()
{    
    //Set to internal clock and 8 TAD
    ADCON2 = 0xA7;
    
    //Set reference voltage to supply voltage
    ADCON1 = 0x00;
    
    //Set ADC as inputs
    TRISAbits.RA0 = 0;
    ANSELAbits.ANSA0 = 0;
    
    //Set ADC as inputs
    TRISAbits.RA1 = 0;
    ANSELAbits.ANSA1 = 0;
    
    //Set ADC as inputs
    TRISAbits.RA2 = 0;
    ANSELAbits.ANSA2 = 0;
    
    //Set ADC as inputs
    TRISAbits.RA3 = 0;
    ANSELAbits.ANSA3 = 0;
}

unsigned int adc_convert(unsigned char ch)
{
    //Check invalid Channel
    if(ch>4) return 0;
    
    //Select ADC Channel
    ADCON0=0x00;
    ADCON0=(unsigned int)(ch<<2);
    
    //Set ADC on
    ADCON0bits.ADON = 1;
    
    //Start conversion
    ADCON0bits.GODONE =1;
    
    //Wait for conversion to finish
    while(ADCON0bits.GODONE);
    
    //Set ADC off
    ADCON0bits.ADON = 0;

    if(ADRES<7) return 0;
    
    return ADRES;
}

unsigned int read_piezo()
{
    unsigned int piezo0, piezo1, piezo2, piezo3;
    static unsigned int piezo_tot = 0;
    
    //Read ADC values
    piezo0 = adc_convert(0);
    piezo1 = adc_convert(1);
    piezo2 = adc_convert(2);
    piezo3 = adc_convert(3);
    
    //Integrate ADC values
    piezo_tot = piezo_tot + piezo0 - piezo1 + piezo2 - piezo3;
    if (piezo_tot > 1536)
    {
        piezo_tot = 0;
    }
    return piezo_tot;
}