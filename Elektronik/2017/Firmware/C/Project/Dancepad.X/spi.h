/* 
 * File:   spi.h
 * Author: astoc
 *
 * Created on 19. March 2018, 23:06
 */

#ifndef SPI_H
#define	SPI_H

//Init SPI master subroutine
void init_spimaster();

//Init SPI slave subroutine
void init_spislave();

//Send SPI master subroutine
unsigned char send_spimaster(unsigned char data);

//Send SPI master subroutine
unsigned char rec_spislave(unsigned char data);

#endif

