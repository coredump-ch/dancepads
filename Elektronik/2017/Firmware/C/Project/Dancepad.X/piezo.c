/* 
 * File:   piezo.c
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#include <xc.h>

void init_piezo()
{    
    //Set to internal clock and 0 TAD
      ADCON2 = 0x07;
    
    //Set reference voltage to supply voltage
    ADCON1 = 0x00;
    
    //Set ADC as inputs
    TRISAbits.RA0 = 1;
    ANSELAbits.ANSA0 = 1;
    
    //Set ADC as inputs
    TRISAbits.RA1 = 1;
    ANSELAbits.ANSA1 = 1;
    
    //Set ADC as inputs
    TRISAbits.RA2 = 1;
    ANSELAbits.ANSA2 = 1;
    
    //Set ADC as inputs
    TRISAbits.RA3 = 1;
    ANSELAbits.ANSA3 = 1;
}

unsigned int adc_convert(unsigned char ch)
{
    //Check invalid Channel
    if(ch>4) 
    {
        return 0;
    }
    
    //Select ADC Channel
    ADCON0=0x00;
//    ADCON0=(unsigned int)(ch<<2);
    ADCON0=(ch<<2);
    
    //Set ADC on
    ADCON0bits.ADON = 1;
    
    //Start conversion
    ADCON0bits.GODONE =1;
    
    //Wait for conversion to finish
    while(ADCON0bits.GODONE);
    
    //Set ADC off
    ADCON0bits.ADON = 0;

//    if(ADRES<7) return 0;
    
    return ADRESH;
}

unsigned int read_piezo(unsigned int* piezoData)
{
    unsigned int piezo1, piezo2, piezo3, piezo4;
    static unsigned int piezo_tot = 0;
    
    //Read ADC values
    piezo1 = adc_convert(0);
    piezo2 = adc_convert(1);
    piezo3 = adc_convert(2);
    piezo4 = adc_convert(3);
    
    //Integrate ADC values
    piezo_tot = piezo_tot + (piezo1 - piezo2 + piezo3 - piezo4)/64;
    
    piezoData[0] = piezo_tot;
    piezoData[1] = piezo1;
    piezoData[2] = piezo2;
    piezoData[3] = piezo3;
    piezoData[4] = piezo4;
    
    return(piezo_tot);
}