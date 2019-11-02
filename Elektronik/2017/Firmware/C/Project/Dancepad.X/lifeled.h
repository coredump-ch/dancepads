/* 
 * File:   lifeled.h
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#ifndef LIFELED_H
#define	LIFELED_H

//Init life LED subroutine
void init_lifeled();

//Blink life LED subroutine
void blink_lifeled();
/*
//Blink life LED interrupt
void high_priority interrupt interrupt_lifeled();
*/
//Blink SPI LED subroutine
void blink_spiled(unsigned char dir, unsigned int freq);

#endif