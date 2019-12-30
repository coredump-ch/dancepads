/* 
 * File:   i2c.h
 * Author: astoc
 *
 * Created on 19. April 2018, 17:29
 */

#ifndef I2C_H
#define	I2C_H

#define I2CDATASIZE 8

#define NOTTRANSMITTED 0
#define TRANSMITTING 1
#define TRANSMITTED 2

#define NOTRECEIVED 0
#define RECEIVING 1
#define RECEIVED 2

//Init I2C (USB) slave subroutine
void init_i2cslave();

//Receive I2C (USB) subroutine
void __interrupt () rec_i2c(unsigned char data);

//Get data from I2C (USB) subroutine
int get_i2c_data(unsigned char* data);

//Send data to I2C (USB) subroutine
int send_i2c_data(unsigned char* data);

#endif

