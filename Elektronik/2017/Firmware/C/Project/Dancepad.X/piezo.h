/* 
 * File:   piezo.h
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#ifndef PIEZO_H
#define	PIEZO_H

//Init Piezo subroutine
void init_piezo();

//Read ADC value subroutine
unsigned int adc_convert(unsigned char);

//Read Piezo value subroutine
unsigned int read_piezo();

#endif // PIEZO_H

