#ifndef PIEZO_H
#define	PIEZO_H

void init_piezo(); // Init Piezo subroutine
unsigned int adc_convert(unsigned char);  // Read ADC value subroutine
unsigned int read_piezo();

#endif // PIEZO_H

