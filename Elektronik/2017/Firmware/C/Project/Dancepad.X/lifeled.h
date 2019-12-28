/* 
 * File:   lifeled.h
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#ifndef LIFELED_H
#define	LIFELED_H

// init life LED subroutine
void init_lifeled();

// blink life LED subroutine
void blink_lifeled(unsigned char dir);
/*
// blink life LED interrupt
void high_priority interrupt interrupt_lifeled();
*/
// blink SPI LED subroutine
void blink_spiled(unsigned char dir, unsigned int freq);

// set life LED 
void set_lifeLed(unsigned char led);

#endif