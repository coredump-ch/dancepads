/* 
 * File:   i2c.h
 * Author: astoc
 *
 * Created on 19. April 2018, 17:29
 */

#ifndef I2C_H
#define	I2C_H

//Init I2C slave subroutine
void init_i2cslave();

//Send I2C subroutine
void send_i2c(unsigned char data);

//Receive I2C subroutine
unsigned char interrupt rec_i2c(unsigned char data);
//unsigned char rec_i2c(unsigned char data);

/*
* For PIC18 devices the high interrupt vector is found at
* 00000008h. The following code will branch to the
* high_interrupt_service_routine function to handle
* interrupts that occur at the high vector.
*/
/*#pragma code high_vector=0x08
void interrupt_at_high_vector(void)
{
_asm GOTO rec_i2c _endasm
}*/

#endif

