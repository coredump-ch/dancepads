/* 
 * File:   spimaster.h
 * Author: astoc
 *
 * Created on 19. March 2018, 23:06
 */

#ifndef SPIMASTER_H
#define	SPIMASTER_H

//Init SPI master subroutine
void init_spimaster();

//Init SPI slave subroutine
void init_spislave();

//Send SPI master subroutine
void send_spimaster(unsigned char data);

//Send SPI master subroutine
void rec_spimaster();

//Send SPI master subroutine
void send_spislave();

//Send SPI master subroutine
unsigned int rec_spislave();

#endif

