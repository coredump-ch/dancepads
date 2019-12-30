/* 
 * File:   spi.h
 * Author: astoc
 *
 * Created on 19. March 2018, 23:06
 */

#ifndef SPI_H
#define	SPI_H

#define SPIDATASIZE 8

#define NOTRECEIVED 0
#define RECEIVING 1
#define RECEIVED 2

//Init SPI master subroutine
void init_spimaster();

//Init SPI slave subroutine
void init_spislave();

//Send SPI master subroutine
unsigned char send_spimaster(unsigned char data);

//receive SPI slave subroutine
unsigned char rec_spislave(unsigned char data);

//receive interrupt SPI slave subroutine
void __interrupt () rec_spi(unsigned char data);

#endif

